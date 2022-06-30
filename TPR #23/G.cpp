// Problem: G. 竹子加分棒與竹子扣分棒 (Bamboo)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	// fastio;
	int n, c, t, k1, k2, k3;

	cin >> n >> c >> t >> k1 >> k2 >> k3;
	int diff = n-c;
	int left  = diff%max(k1, k2);
	int right = max(k1, k2)-diff%max(k1, k2);
	
	if (n+max(k1, k2)*t <= c){
		cout << n+max(k1, k2)*t << "\n";
	}else{
		cout << diff/max(k1, k2)
	}
	
	return 0;
}