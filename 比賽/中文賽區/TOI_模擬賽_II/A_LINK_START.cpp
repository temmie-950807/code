#include <bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// declare
const int MAX_SIZE=1e5+5;
const int INF=6e18;

int h, m, q;
string a, b;

vector<int> diff_cnt(100005);

// function
pair<int, int> get_data(string s){
    int hh=(s[0]-'0')*10+(s[1]-'0')*1;
    int mm=(s[3]-'0')*100+(s[4]-'0')*10+(s[5]-'0')*1;
    return {hh, mm};
}
string itoa(int n, int k){
    string ret="";
    while (n){
        ret=(char)(n%10+'0')+ret;
        n/=10;
    }
    while (ret.size()<k){
        ret='0'+ret;
    }
    return ret;
}

signed main(){
    fastio;

    // input
    cin >> h >> m >> q;

    // pre-process
    string from=itoa(0, 2)+':'+itoa(0, 3);
    string goal=from;

    do{
        // split "from"
        vector<int> v;
        for (int i=0 ; i<from.size() ; i++){
            if (from[i]==':') continue;
            else{
                v.push_back(from[i]-'0');
            }
        }
        sort(v.begin(), v.end());

        // get all permutation
        pair<int, int> data_a, data_b;
        data_a=get_data(from);
        do{
            string tmp="";
            tmp+=v[0]+'0';
            tmp+=v[1]+'0';
            tmp+=':';
            tmp+=v[2]+'0';
            tmp+=v[3]+'0';
            tmp+=v[4]+'0';

            data_b=get_data(tmp);

            // get diff
            if (data_b.first>=h || data_b.second>=m) continue;
            int diff=((data_a.first*m+data_a.second)+h*m);
            diff-=(data_b.first*m+data_b.second);
            diff%=h*m;

            // record
            diff_cnt[diff]++;
        } while (next_permutation(v.begin(), v.end()));

        // change number
        if (++data_a.second>=m){
            data_a.second=0;
            data_a.first++;
            if (data_a.first>=h) data_a.first=0;
        }
        from=itoa(data_a.first, 2)+':'+itoa(data_a.second, 3);
    } while (from!=goal);

    // queries
    for (int i=0 ; i<q ; i++){
        // input
        cin >> a >> b;

        // get data
        pair<int, int> data_a, data_b;
        data_a=get_data(a);
        data_b=get_data(b);

        // get diff
        int diff=((data_a.first*m+data_a.second)+h*m);
        diff-=(data_b.first*m+data_b.second);
        diff%=h*m;

        // output
        cout << diff_cnt[diff] << "\n";

    }
    return 0;
}