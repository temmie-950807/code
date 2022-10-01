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
int n, tmp;

int solve(string s){
    // init
    int ret=-1;
    int dp[1005][1005];

    for (int i=1 ; i<=s.size() ; i++){
        dp[i][i]=1;
    }

    // dp
    for (int j=1 ; j<=s.size() ; j++){
        for (int i=s.size() ; i>=1 ; i--){
            dp[i][j]=0;


            // i~j
            if (i<j){
                cout << "i: " << i << " j: " << j << endl;
            //     if (s[i-1]==s[j-1]){
            //         dp[i][j]=max(dp[i][j], dp[i+1][j-1]+2);
            //     }else{
            //         dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            //     }
            //     ret=max(ret, dp[i][j]);
            }
        }
    }

    // preview
    // for (int j=0 ; j<s.size() ; j++){
    //     for (int i=0 ; i<s.size() ; i++){
    //         cout << dp[j][i] << " ";
    //     }   cout << endl;
    // }
    return ret;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        string a;
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}