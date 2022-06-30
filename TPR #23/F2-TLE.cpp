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
	int t, tmp;
	vector<int> k(t+10, 0);
	
	cin >> t;
	for (int i=0 ; i<t ; i++){
		cin >> k[i];
	}
	k[t]=k[t-1]+1;
 
	int p1=0, p2=0;
	int x=(k[0]&1);
	for (int i=1 ; i<=t ; i++){
		if ((k[i]&1)==x){
			p2++;
		}else{
			x = (k[i]&1);
			sort(k.begin()+p1, k.begin()+p2+1);
			p1 = i;
			p2 = i;
		}
	}
	
	for (int i=0 ; i<t ; i++){
		cout << k[i];
	}
	return 0;
}