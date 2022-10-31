// Problem: A. Another String Minimization Problem
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
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, m, tmp;
string output;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		output = "";
		
		// input
		cin >> n >> m;
		for (int i=0 ; i<m ; i++){
			output += "B";
		}
		
		// process
		for (int i=0 ; i<n ; i++){
			cin >> tmp;
			
			int k = m+1-tmp;
			// cout << "tmp: " << tmp << " " << k << "\n";
			
			if (tmp>k){
				tmp ^= k;
				k ^= tmp;
				tmp ^= k;
			}
			tmp--;
			k--;
			
			
			if (output[tmp]=='B'){
				output[tmp]='A';
				// cout << i << " " << __LINE__ << "\n";
			}else if (output[k]=='B'){
				output[k]='A';
				// cout << i << " " << __LINE__ << "\n";
			}
		}
        
        // output
        cout << output << "\n";
	}
    return 0;
}