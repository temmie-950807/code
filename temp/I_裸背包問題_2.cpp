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
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, w, v, q, tmp;
vector<int> ww(1), vv(1), qq(1);
int dp[105][MAX_SIZE];

void solve(){
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> w >> v;
        ww.push_back(w);
        vv.push_back(v);
    }
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> tmp;
        qq.push_back(tmp);
    }

    // dp
    for (int i=1 ; i<=n ; i++){
        for (int j=0 ; j<MAX_SIZE ; j++){
            if (j-ww[i]>=0){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-ww[i]]+vv[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    // output
    for (int i=1 ; i<=q ; i++){
        string s="";
        int now=dp[n][qq[i]];

        while (now!=0){
            
        }
    }

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