// Problem: C. Train and Queries
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
int t, n, q, tmp, a, b;
map<int, int> start, goal;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		start.clear();
		goal.clear();
		
		// input
		cin >> n >> q;
        for (int i=1 ; i<=n ; i++){
        	cin >> tmp;
			if (start[tmp]==0) start[tmp] = i;
        	goal[tmp] = i;
        }

		for (int i=0 ; i<q ; i++){
			cin >> a >> b;
			if (start[a]==0 || goal[b]==0){
				cout << "NO\n";
			}else{
				if (start[a]<=goal[b]){
					cout << "YES\n";
				}else{
					cout << "NO\n";
				}
			}
		}
	}
    return 0;
}