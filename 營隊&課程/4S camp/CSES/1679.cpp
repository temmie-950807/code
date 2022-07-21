// Problem: Course Schedule
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
bool check=0;
int n, m, a, b;
vector<int> vis(MAX_SIZE, 0), G[MAX_SIZE], output;

void DFS(int x){
	vis[x] = 2; // on road
	for (auto y : G[x]){
		if (vis[y]==2){
			check = 1;
			return;
		}
		if (vis[y]==0){
			DFS(y);
		}
	}
	
	vis[x] = 1; // pass , not on road
	output.PB(x);
	return;
}

void BFS(int x){
	
}


signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
	for (int i=0 ; i<m ; i++){
		cin >> a >> b;
		G[a].PB(b);
	}
	
	// DFS
	for (int i=1 ; i<=n ; i++){
		if (vis[i]==0){
			DFS(i);
		}
	}
	
	if (check == 1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}else{
		reverse(output.begin(), output.end());
		for (auto x : output){
			cout << x << " ";
		}   cout << "\n";
	}
    return 0;
}