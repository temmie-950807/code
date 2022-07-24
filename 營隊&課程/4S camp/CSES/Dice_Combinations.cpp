#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e6+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;

// declare
int n;
vector<int> dp(MAX_SIZE, 0);

signed main(void){
	fastio;
	
    // pre-process
    for (int i=1 ; i<MAX_SIZE ; i++){
        if (i<=6){
            dp[i]++;
        }
        
        for (int j=1 ; j<=6 ; j++){
            if (i-j>=1){
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }

	cin >> n;
    cout << dp[n] << "\n";
    return 0;
}