// Problem: F1. 立夏和煦九降風，遠近馳名即風城 (Hsinchu)【Easy Version】
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
	int t, n, tmp;
	vector<int> k;
	
	cin >> t;
	for (int i=0 ; i<t ; i++){
		cin >> tmp;
		k.push_back(tmp);
	}
	
	for (int i=0 ; i<t ; i++){
		for (int j=i+1 ; j<t ; j++){
			if (k[i]>k[i+1] && k[i+1]%2 == k[i]%2){
				k[i]^=k[i+1];
				k[i+1]^=k[i];
				k[i]^=k[i+1];
			}
		}
	}
	return 0;
}