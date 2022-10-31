// Problem: C. Cypher
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
int t, n, k, tmp;
string s;
vector<int> key;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		key.clear();
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	key.emplace_back(tmp);
        }
        for (int i=0 ; i<n ; i++){
        	cin >> k >> s;
        	for (int j=0 ; j<s.size() ; j++){
        		if (s[j]=='D'){
        			key[i]++;
        			key[i]%=10;
        		}else{
        			key[i]--;
        			if (key[i]==-1){
        				key[i]=9;
        			}
        		}
        	}
        }
        
        // output
        for (auto x : key){
        	cout << x << " ";
        }   cout << "\n";
	}
    return 0;
}