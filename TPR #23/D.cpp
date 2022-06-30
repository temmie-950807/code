// Problem: D. 竹子畫筆 (Bamboo Pencil)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	int t, l, r;
	int s=0;
	
	cin >> t;
	while (t--){
		cin >> l >> r;
		s += l*r;
	}
	cout << s;
	return 0;
}