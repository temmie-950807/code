// Problem: A. 最大取餘 (Math Problem)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	int n;
	cin >> n;
	if (n%2==0) cout << n%(n/2+1) << "\n";
	else cout << n%(n/2+1) << "\n";
	return 0;
}