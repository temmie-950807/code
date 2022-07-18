// Problem: A. Mark the Photographer
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 1e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, k, tmp, check;
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		check = 0;
		v.clear();
		
		cin >> n >> k;
        for (int i=0 ; i<2*n ; i++){
        	cin >> tmp;
        	v.push_back(tmp);
        }
	
		sort(v.begin(), v.end());
		for (int i=0 ; i<n ; i++){
			if (v[i]+k>v[n+i]){
				check = 1;
				break;
			}
		}
		
		// output
		if (check) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}