#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 1e3+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
// declare
int n;
char ip[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
 
void solve(){
    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            cin >> ip[i][j];
        }
    }
 
    // dp
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            if (i==1 && j==1 && ip[1][1]!='*'){
                dp[1][1]=1;
            }else if (ip[i][j]=='*'){
                continue;
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
 
    // preview
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            cout << dp[i][j] << " ";
        }   cout << endl;
    }
 
    // output
    cout << dp[n][n];
    return;
}
 
signed main(void){
    fastio;
 
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}