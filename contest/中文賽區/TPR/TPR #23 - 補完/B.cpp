// Problem: B. 企鵝的出遊計畫 (Travel Plan)
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
	int n;
	cin >> n;
	
	if (n%2==1) cout << n/2+1;
	else cout << n/2;
	return 0;
}