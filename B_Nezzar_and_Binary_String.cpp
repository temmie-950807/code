#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

// declare
int n, q;
string s1, s2;
int a, b;
vector<pair<int, int>> v;
map<int, int> ss;

// fast IO
inline char readchar(){
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}
inline int nextint(){
    int x = 0, c = readchar(), neg = false;
    while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
    if(c == '-') neg = true, c = readchar();
    while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
    if(neg) x = -x;
    return x; // returns 0 if EOF
}
inline string nextstring(){
    string x="";
    char c=readchar();
    while(('0' > c || c > '9') && c!=EOF) c=readchar();
    while('0' <= c && c <= '9') x+=c, c=readchar();
    return x; // returns 0 if EOF
}

// function
void split(map<int, int> &ss, int pos){
    auto it=ss.lower_bound(pos);
    if (it->first!=pos){
        int tmp=prev(it)->second;
        ss[pos]=tmp;
    }
}

bool _merge(map<int, int> &ss, int l, int r){
    auto it_l=ss.lower_bound(l);
    auto it_r=ss.lower_bound(r);

    int A=0;
    int B=0;
    for (auto it=it_l ; it!=it_r ; it++){
        if (it->second==0){
            A+=next(it)->first-it->first;
        }else{
            B+=next(it)->first-it->first;
        }
    }

    if (A==B){
        return 0;
    }else if (A<B){
        ss.erase(it_l, it_r);
        ss[l]=1;
        return 1;
    }else{
        ss.erase(it_l, it_r);
        ss[l]=0;
        return 1;
    }
}


void solve(){
    n=nextint();
    q=nextint();

    // init
    v.clear();
    ss.clear();
    ss[-1]=0;
    ss[n]=0;

    // input
    s1=nextstring();
    s2=nextstring();
    for (int i=0 ; i<q ; i++){
        a=nextint();
        b=nextint();
        v.push_back({a, b});
    }

    char now_1=s2[0];
    ss[0]=now_1-'0';
    for (int i=1 ; i<n ; i++){
        if (s2[i]!=now_1){
            now_1=s2[i];
            ss[i]=now_1-'0';
        }
    }

    // process
    for (int i=q-1 ; i>=0 ; i--){
        int ll=v[i].first;
        int rr=v[i].second;
        ll--;

        split(ss, ll);
        split(ss, rr);
        if (_merge(ss, ll, rr)==0){
            cout << "NO" << endl;
            return;
        }
    }

    // check answer
    int i=0, now_2=0;
    for (auto x : ss){
        while (i<x.first && i<s1.size()){
            if (s1[i]-'0'!=now_2){
                cout << "NO" << endl;
                return;
            }
            i++;
        }
        now_2=x.second;
    }
    cout << "YES" << endl;
    return;
}

signed main(void){
    fastio;

    int t=1;
    t=nextint();
    while (t--){
        solve();
    }
    return 0;
}