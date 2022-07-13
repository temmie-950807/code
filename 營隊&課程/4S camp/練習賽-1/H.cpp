// Problem: H. 度假問題 (Vacation)
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e6+5
using namespace std;

// declare
int n, k, a, b, c, output=1;
int input[10][MAX_SIZE], dp[10][MAX_SIZE]; // 狀態: 到i天選擇a, b, c的最大快樂度

signed main(void){
	fastio;
	
	// input
	cin >> n >> k;
	for (int i=1 ; i<=n ; i++){
		cin >> a >> b >> c;
		input[1][i] = a;
		input[2][i] = b;
		input[3][i] = c;
	}
	
	// dp - fixed A
	memset(dp, 0, sizeof(dp));
	for (int i=1 ; i<=n ; i++){
		if (i==1){
			dp[1][1] = input[1][1];
			dp[2][1] = 0;
			dp[3][1] = 0;
		}else if ((i-1)>=(k+1) && (i-1)%(k+1)==0){
			dp[1][i] = max(dp[2][i-1], dp[3][i-1])+input[1][i];
			dp[2][i] = dp[2][i-1]+0;
			dp[3][i] = dp[3][i-1]+0;
		}else {
			dp[1][i] = max(dp[2][i-1], dp[3][i-1])+input[1][i];
			dp[2][i] = max(dp[1][i-1], dp[3][i-1])+input[2][i];
			dp[3][i] = max(dp[1][i-1], dp[2][i-1])+input[3][i];
		}
	}
	output = max({output, dp[1][n], dp[2][n], dp[3][n]});
	
	// dp - fixed B
	memset(dp, 0, sizeof(dp));
	for (int i=1 ; i<=n ; i++){
		if (i==1){
			dp[1][1] = 0;
			dp[2][1] = input[2][1];
			dp[3][1] = 0;
		}else if ((i-1)>=(k+1) && (i-1)%(k+1)==0){
			dp[1][i] = dp[1][i-1]+0;
			dp[2][i] = max(dp[1][i-1], dp[3][i-1])+input[2][i];
			dp[3][i] = dp[3][i-1]+0;
		}else {
			dp[1][i] = max(dp[2][i-1], dp[3][i-1])+input[1][i];
			dp[2][i] = max(dp[1][i-1], dp[3][i-1])+input[2][i];
			dp[3][i] = max(dp[1][i-1], dp[2][i-1])+input[3][i];
		}
	}
	output = max({output, dp[1][n], dp[2][n], dp[3][n]});
	
	// dp - fixed C
	memset(dp, 0, sizeof(dp));
	for (int i=1 ; i<=n ; i++){
		if (i==1){
			dp[1][1] = 0;
			dp[2][1] = 0;
			dp[3][1] = input[3][1];
		}else if ((i-1)>=(k+1) && (i-1)%(k+1)==0){
			dp[1][i] = dp[1][i-1]+0;
			dp[2][i] = dp[2][i-1]+0;
			dp[3][i] = max(dp[1][i-1], dp[2][i-1])+input[3][i];
		}else {
			dp[1][i] = max(dp[2][i-1], dp[3][i-1])+input[1][i];
			dp[2][i] = max(dp[1][i-1], dp[3][i-1])+input[2][i];
			dp[3][i] = max(dp[1][i-1], dp[2][i-1])+input[3][i];
		}
	}
	output = max({output, dp[1][n], dp[2][n], dp[3][n]});
	cout << output << "\n";

    return 0;
}