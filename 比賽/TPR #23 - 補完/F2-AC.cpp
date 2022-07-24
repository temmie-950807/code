// Problem: F2. 立夏和煦九降風，遠近馳名即風城 (Hsinchu)【Hard Version】
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
	int t, tmp, p=0;
	vector<int> k[t+100];
	
	cin >> t;
	for (int i=0 ; i<t ; i++){
		cin >> tmp;
		if (tmp%2!=p%2){
			k[++p].push_back(tmp);
		}else{
			k[p].push_back(tmp);
		}
	}

	for (int i=0 ; i<=p ; i++){
		sort(k[i].begin(), k[i].end());
		for (auto x : k[i]){
			cout << x;
		}
	}
	return 0;
}