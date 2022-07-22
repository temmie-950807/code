// Problem: D - Restricted Permutation
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
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, m, a, b;
vector<int> G[MAX_SIZE], k(MAX_SIZE, 0), output;
priority_queue<int, vector<int>, greater<int>> pq;

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
	for (int i=0 ; i<m ; i++){
		cin >> a >> b;
		G[a].PB(b);
		k[b]++;
	}
	
	for (int i=1 ; i<=n ; i++){
		if (k[i]==0){
			pq.push(i);
			k[i] = INF;
		}
	}
	
	while (pq.size()){
		int now = pq.top();
		pq.pop();
		
		output.PB(now);
		
		for (auto x : G[now]){
			k[x]--;
			
			if (k[x]==0){
				pq.push(x);
				k[x] = INF;
			}
		}
	}
	
	if (output.size()==n){
		for (auto x : output) cout << x << " ";
		cout << "\n";
	}else{
		cout << "-1\n";
	}
    return 0;
}