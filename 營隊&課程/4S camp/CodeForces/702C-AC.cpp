#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE 100
using namespace std;

int cube(int x){
	return x*x*x;
}

signed main(void){
	fastio;

	int t, n, c;
	
	cin >> t;
	while (t--){
		// init
		c = 0;

		// input
		cin >> n;

		// unumerate
		for (int i=1 ; i<cbrt(n)+1 ; i++){
			if ((cbrt(n - cube(i)))==(int)(cbrt(n - cube(i))) && cbrt(n - cube(i))>0){
				cout << "YES\n";
				c = 1;
				break;
			}
		}

		// output
		if (c==0){
			cout << "NO\n";
		}
	}
	
}