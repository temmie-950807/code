// Problem: F. Equate Multisets
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
vector<int> a, b;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		a.clear();
		b.clear();
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	a.push_back(tmp);
        }
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	
        }
	}
    return 0;
}