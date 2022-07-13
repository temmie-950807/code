// Problem: E. Split Into Two Sets
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

// declare
int t, n, a, b, s, k;
vector<int> path[MAX_SIZE];

signed main(void){
	// fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		for (int i=0 ; i<MAX_SIZE ; i++){
			path[i].clear();
		}
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> a >> b;
        	path[a].push_back(b);
        	path[b].push_back(a);
        }
        
        // process
		for (int i=1 ; i<=n ; i++){
			cout << "i: " << i << "\n";
			if (path[i][0]!=-1){
				s = 1;
				k = path[i][0];
				path[i][0] = -1;

				while (1){
					cout << "k: " << k << "\n";
					if (path[k][0]!=-1){
						k = path[i][0];
						path[k][0] = -1;
					}else if (path[k][1]!=-1){
						k = path[i][1];
						path[k][0] = -1;
					}else{
						break;
					}
					s++;
				}

				if (s%2==1){
					cout << "NO\n";
				}else{
					cout << "YES\n";
				}
			}else if (path[i][1]!=-1){
				s = 1;
				k = path[i][1];
				path[i][1] = -1;

				while (1){
					cout << "k: " << k << "\n";
					if (path[k][0]!=-1){
						k = path[i][0];
						path[k][0] = -1;
					}else if (path[k][1]!=-1){
						k = path[i][1];
						path[k][0] = -1;
					}else{
						break;
					}
					s++;
				}

				if (s%2==1){
					cout << "NO\n";
				}else{
					cout << "YES\n";
				}
			}
		}
	}
    return 0;
}