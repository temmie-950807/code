#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

// debugger
// ===================================
bool debug_mode=true;
#define cerr if(debug_mode) cerr
#define dbg(x) cerr << #x << " = " << x << endl
// ===================================

// declare
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

string tmp, s;

void solve1(){
    
    s="";
    getline(cin, tmp);

    for (int i=0 ; i<tmp.size();  i++){
        if ('a'<=tmp[i] && tmp[i]<='z'){
            s+=tmp[i];
        }else if ('A'<=tmp[i] && tmp[i]<='Z'){
            s+=tmp[i]-'A'+'a';
        }
    }

    if (s.size()==0){
        cout << "N";
        return;
    }

    string q=s;
    reverse(q.begin(), q.end());
    if (s==q){
        cout << "Y";
        return;
    }
    for (int i=0 ; i<s.size() ; i++){
        string p=s.substr(0, i);
        p+=s.substr(i+1);
        string q=p;
        reverse(q.begin(), q.end());

        if (p==q){
            cout << "Y";
            return;
        }
    }

    cout << "N";
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    cin.ignore();
    while (t--){
        solve1();
    }
    return 0;
}