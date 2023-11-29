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
#pragma GCC optimize("O3,unroll-loops")
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
const int MAX_N = 1e7+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

vector<vector<pair<int, int>>> G(MAX_N);
vector<pair<int, int>> v(1, {0, -1});
vector<int> ip;

// function
void wa(){
    cout << "WA QQ\n";
    exit(0);
}

int dfs(int a, int b){
    int ret=0;

    for (auto x : G[a]){
        ret=max(ret, dfs(x.first, x.second));
    }

    return ret+b;
}

int stoiowo(string s){
    int ret=0;

    for (int i=0 ; i<s.size() ; i++){
        ret*=10;
        ret+=s[i]-'0';
    }

    return ret;
}

void solve1(){

    string s;
    cin >> s;

    if (s=="[]" || s=="[null]"){
        cout << 0 << "\n";
        return;
    }

    s=s.substr(1);
    s.pop_back();
    s+=",";

    string tmp="";
    for (int i=0 ; i<(int)s.size() ; i++){
        if (s[i]==','){
            if (tmp=="null"){
                ip.push_back(-1);
            }else{
                if (tmp.size()>17){
                    wa();
                }
                ip.push_back(stoiowo(tmp));
            }
            tmp="";
        }else{
            tmp+=s[i];
        }
    }

    // for (auto x : ip){
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    int now=0, nxt=1;
    for (auto x : ip){
        if (x==-1) now++;
        else{
            G[now].push_back({nxt, x});
            nxt++;
        }
    }

    // for (int i=0 ; i<=10 ; i++){
    //     cerr << i << ": ";
    //     for (auto x : G[i]){
    //         cerr << x.second << " ";
    //     }
    //     cerr << '\n';
    // }

    cout << dfs(0, 0) << "\n";
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}