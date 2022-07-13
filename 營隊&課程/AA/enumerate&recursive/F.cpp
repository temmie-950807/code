// Problem: F. 順路 1
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
int n, q, tmp;
int pass, goal;
vector<int> tree[MAX_SIZE], output(MAX_SIZE, 0);
vector<pair<int, int>> query[MAX_SIZE];
bitset<MAX_SIZE> p(0);

void DFS(int x){
	// pass the node
	p[x] = 1;
	
	// check query
	for (int i=0 ; i<query[x].size() ; i++){
		// cout << "query: " << query[x][i].first << "\n";
		output[query[x][i].second] = p[query[x][i].first];
	}
	
	// recursive
	for (auto y : tree[x]){
		// cout << "y: " << y << "\n";
		DFS(y);
	}
	
	// back
	p[x] = 0;
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=2 ; i<=n ; i++){
		cin >> tmp;
		tree[tmp].push_back(i);
	}
	cin >> q;
	for (int i=1 ; i<=q ; i++){
		cin >> pass >> goal;
		query[goal].push_back({pass, i}); // 如果DFS到了goal , 就會去尋找所有的pass
	}
	
	// DFS
	DFS(1);
	
	// output
	for (int i=1 ; i<=q ; i++){
		cout << output[i] << "\n";
	}
    return 0;
}