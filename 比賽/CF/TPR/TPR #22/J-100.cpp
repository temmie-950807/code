// Problem: J. 做一休四 (Do One Day)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

const int N=2e5+5;
int input[N], pre[N];
int dp[N][2];

signed main(void){
	fastio;
	int n;

	cin >> n;
	for (int i=1 ; i<=n ; i++){
		cin >> input[i];
		pre[i] = pre[i-1] + input[i];
	}

	for (int i=1 ; i<=n ; i++){
		// 只要不請假的話, 就沒有多不多的問題, 直接選取前面較大的即可
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		
		// 如果要請假的話, 那麼第i-4天就不能請假
		// 並且加上區間和
		if (i-4>=0) dp[i][1] = dp[i-4][0] + pre[i] - pre[i-4];
	}

	cout << max(dp[n][0], dp[n][1]) << "\n";
	return 0;
}