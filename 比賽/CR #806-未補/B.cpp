// Problem: B. ICPC Balloons
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
int t, n, output;
string s;
vector<int> k(100, 0);

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		fill(k.begin(), k.end(), 0);
		output = 0;
		
		// input
		cin >> n >> s;
		for (int i=0 ; i<n ; i++){
			if (k[s[i]-'A']==0){
				output += 2;
				k[s[i]-'A']++;
			}else{
				output += 1;
				k[s[i]-'A']++;
			}
		}
		
		// output
		cout << output << "\n";
        
	}
    return 0;
}