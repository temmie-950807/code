// Problem: E. 團報優惠 (Group Discounts)
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
	vector<int> k(300000+100, 0);
	int n, tmp;
	int a=0, b=0;
	
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		k[tmp]++;
	}
	
	for (int i=0 ; i<k.size() ; i++){
		if (k[i]>=10) a++;
		if (k[i]>=15) b++;
	}
	
	cout << a << ' ' << b << "\n";
	return 0;
}