#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp;
vector<int> v, dp(MAX_SIZE);

void solve(){
    // init
    v.resize(1, 0);
    fill(dp.begin(), dp.end(), INF); // 選到i時 會剩下的格子

    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // dp
    dp[0]=0;
    for (int i=1 ; i<=n ; i++){
        if (i+v[i]<=n && dp[i-1]==0){
            dp[i+v[i]]=0;
        }
        if (i-v[i]-1>=0 && dp[i-v[i]-1]==0){
            dp[i]=0;
        }

        if (dp[i]==INF){
            dp[i]=dp[i-1]+1;
        }
    }

    // preview
    // for (int i=1 ; i<=n ; i++){
    //     cout << dp[i] << " ";
    // }   cout << endl;

    // output
    cout << (dp[n]==0 ? "YES" : "NO") << endl;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}