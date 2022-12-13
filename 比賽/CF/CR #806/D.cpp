// Problem: D. Double Strings
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
int t, n;
string tmp;
vector<string> v, p;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		v.clear();
		p.clear();
		
		cin >> n;
		vector<bool> output(n, 0);
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	v.push_back(tmp);
        	p.push_back(tmp);
        }
        
        sort(p.begin(), p.end());
        
        for (int i=0 ; i<n ; i++){
        	for (int j=1 ; j<v[i].size() ; j++){
        		bool b1=binary_search(p.begin(), p.end(), v[i].substr(0, j));
        		bool b2=binary_search(p.begin(), p.end(), v[i].substr(j));
        		// cout << "===\n";
        		// cout << v[i].substr(0, j) << " " << v[i].substr(j) << "\n";
        		// cout << b1 << " " << b2 << "\n";
        		if (b1==1 && b2==1){
        			output[i] = 1;
        		}
        	}
        }
        
        // output
        for (auto x : output){
        	cout << x;
        }   cout << "\n";
	}
    return 0;
}