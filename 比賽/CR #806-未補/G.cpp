// Problem: G. Good Key, Bad Key
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, k, tmp, s, output, z;
vector<int> input, p;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		input.clear();
		p.clear();
		output = 0;
		s = 0;
		z = 1;
		
		// input
		cin >> n >> k;
		for (int i=0 ; i<n ; i++){
			cin >> tmp;
			s += tmp;
			input.push_back(tmp);
		}
		
		// pre-process
		for (int i=0 ; i<n ; i++){
			p.push_back(s);
			s -= input[i];
		}
		
		cout << "pre-process: ";
		for (auto x : p){
			cout << x << " ";
		}   cout << "\n";
        
		// get output
		for (int i=0 ; i<n ; i++){
			
			// cout << i << " ";
			if (k < p[i]/z/2){ // use good key
				output += input[i]/z;
				output -= k;
			}else{ // use bad key
				z*=2;
				output += input[i]/z;
			}
		}
		// cout << "\n";

		// output
		cout << output << "\n";
	}
    return 0;
}