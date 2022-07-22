#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 5e5+5;
const int INF = 1e18;
const int MOD = 1000000007;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, tmp, output=0;
vector<int> v, dp(MAX_SIZE, 0);

signed main(void){
	fastio;
	
	// input
	cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i=n-1 ; i>=0 ; i--){
        dp[i] += 1;

        if (i-2>=0){
            dp[i-2] += dp[i];
        }
        if (i-1>=0){
            dp[i-1] += dp[i];
        }
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }

    // output
    for (auto x : dp){
        output += x;
        output %= MOD;
        // cout << "output: " << output << "\n";
    }
    cout << output << "\n";
    return 0;
}