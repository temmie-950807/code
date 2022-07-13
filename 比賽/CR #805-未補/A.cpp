// Problem: A. Round Down the Price
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, tmp;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> n;

		int i=1;
		while (i*10<=n){
			i*=10;
		}
		cout << n-i << "\n";
	}
    return 0;
}