// Problem: B. Mark the Dust Sweeper
// Memory Limit: 256 MB
// Time Limit: 1500 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 2e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, tmp, output, check;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		output = 0;
		check = 0;
		
		// input
		cin >> n;
        for (int i=1 ; i<=n ; i++){
        	cin >> tmp;
			if (tmp!=0 && check==0) check=1;
			if (check==1 && tmp==0 && i!=n) output++;
			if (tmp>0 && i!=n) output += tmp;
        }
        
        // output
        cout << output << "\n";
	}
    return 0;
}