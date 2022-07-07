// Problem: C. 竹子物流 (Baggage)
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
	
	if (n<=10) cout << n*100;
	else if (n<=20){
		cout << 10*100+(n-10)*200;
	}else{
		cout << 10*100+10*200+(n-20)*300;
	}
	return 0;
}