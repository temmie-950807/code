// Problem: E. Mirror Grid
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
int t, n, s;
string tmp;
vector<string> v;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		v.clear();
		s=0;
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	v.emplace_back(tmp);
        }
        
        // process
        for (int i=0 ; i<n ; i++){
        	for (int j=0 ; j<n ; j++){
        		int k = 0;
        		if (v[i][j]=='1') k++;
        		if (v[j][n-1-i]=='1') k++;
        		if (v[n-1-j][i]=='1') k++;
        		if (v[n-1-i][n-1-j]=='1') k++;
        		
        		if (k==1){
        			v[i][j]='0';
					v[j][n-1-i]='0';
					v[n-1-j][i]='0';
					v[n-1-i][n-1-j]='0';
					s += 1;
        		}else if (k==2){
					v[i][j]='0';
					v[j][n-1-i]='0';
					v[n-1-j][i]='0';
					v[n-1-i][n-1-j]='0';
					s += 2;
				}else if (k==3){
					v[i][j]='1';
					v[j][n-1-i]='1';
					v[n-1-j][i]='1';
					v[n-1-i][n-1-j]='1';
					s += 1;
				}
        	}
        }
        
        // for (auto x : v){
        	// cout << x << "\n";
        // }
        
        // output
        cout << s << "\n";
	}
    return 0;
}