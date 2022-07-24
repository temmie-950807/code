#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, a, b, ans;
vector<int> G[MAX_SIZE], dp(MAX_SIZE);

void dfs(int now, int p){
    int mx = 0, smx = 0; // 最大, 次大

    for (auto x : G[now]){
        if (x==p) continue; // 確保不會回朔
        dfs(x, now);
        if (dp[x]>mx){
            smx = mx;
            mx = dp[x];
        }else if (dp[x]>smx){
            smx = dp[x];
        }
    }

    dp[now] = mx+1;
    ans = max(ans, mx+smx);
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // process
    dfs(1, 1);

    // output
    cout << ans << "\n";

    return 0;
}