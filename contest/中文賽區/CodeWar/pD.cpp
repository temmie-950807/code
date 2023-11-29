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
const int MAX_N = 2000+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, tmp;
map<int, vector<pair<int, int>>> ss;
vector<vector<int>> ans(MAX_N, vector<int>(MAX_N, -1));

void preview(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cerr << ans[i][j] << " ";
        }
        cerr << "\n";
    }
    cerr << '\n';
}

void solve1(){

    // input
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> tmp;
            ss[tmp].push_back({i, j});
        }
    }

    // process
    for (auto x : ss){

        int ma=0;
        for (auto y : x.second){

            for (int i=0 ; i<n ; i++){
                if (ans[i][y.second]!=-1){
                    ma=max(ma, ans[i][y.second]);
                }
            }
            for (int i=0 ; i<m ; i++){
                if (ans[y.first][i]!=-1){
                    ma=max(ma, ans[y.first][i]);
                }
            }

        }

        for (auto y : x.second){
            ans[y.first][y.second]=ma+1;
        }

        cerr << x.first << "\n";
        preview();
    }

    // output
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
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