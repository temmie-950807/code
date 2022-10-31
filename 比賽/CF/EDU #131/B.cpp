// Problem: B. Permutation
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
int t, n, cnt;
vector<int> output;
 
signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		output.clear();
		cnt=0;
		
		// input
		cin >> n;
		vector<int> vis(n+1, 0);
		
		// process
		for (int j=1 ; j<=n ; j++){
			if (vis[j]==0){
				cnt--;
		        for (int i=j ; i<=n ; i*=2){
		        	vis[i] = 1;
		        	cnt++;
		        	output.push_back(i);
		        }
			}
		}
        
        // output
        cout << 2 << "\n";
        for (auto x : output){
        	cout << x << " ";
        }   cout << "\n";
	}
    return 0;
}