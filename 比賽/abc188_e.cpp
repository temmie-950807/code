// Problem: E - Peddler
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, m, a, b;
vector<int> p(MAX_SIZE), G[MAX_SIZE], k(MAX_SIZE), dp(MAX_SIZE);
queue<int> q;

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
	for (int i=1 ; i<=n ; i++){
		cin >> p[i];
	}
	for (int i=1 ; i<=m ; i++){
		cin >> a >> b;
		G[a].PB(b);
		k[b]++;
	}
	
	for (int i=1 ; i<=n ; i++){
		if (k[i]==0){
			q.push(i);
		}
	}
	
	// BFS
	while(q.size()){
		
	}
    return 0;
}