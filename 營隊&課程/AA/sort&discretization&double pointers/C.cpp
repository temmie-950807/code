// Problem: C. 名次數列
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
#define MAX_SIZE (int)1e5+5

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, tmp;
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		v.clear();
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	v.push_back(tmp);
        }
        
        // process
        vector<int> p = v;
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end())-p.begin());
	
		// output
		for (int i=0 ; i<n ; i++){
			int pos = lower_bound(p.begin(), p.end(), v[i]) - p.begin() + 1;
			cout << pos << " ";
		}   cout << "\n";
	}
    return 0;
}