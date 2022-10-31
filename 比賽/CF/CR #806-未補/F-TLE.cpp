// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, tmp, output;
vector<pair<int, int>> input;
vector<int> p;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		input.clear();
		p.clear();
		output = 0;
		
		// input
		cin >> n;
        for (int i=1 ; i<=n ; i++){
        	cin >> tmp;
        	
        	if (i>tmp){
        		input.push_back({tmp, i});
        	}
        }
        
        // process
        for (int i=0 ; i<input.size() ; i++){
        	int f = input[i].first;
			auto k = lower_bound(p.begin(), p.end(), f);
			
        	output += k-p.begin();
        	
        	// final
        	p.push_back(input[i].second);
        	sort(p.begin(), p.end());
        	
        }
        
        // output
        cout << output << "\n";
	}
    return 0;
}