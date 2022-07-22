// Problem: G - Longest Path
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
vector<int> G[MAX_SIZE], k(MAX_SIZE, 0), dp(MAX_SIZE, 0);
queue<int> q;

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
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
	while (q.size()){
		int now = q.front();
		q.pop();
		
		for (auto x : G[now]){
			k[x]--;
			dp[x] = max(dp[x], dp[now]+1); // dp: 如果有兩個方式可以走到, 就比較誰比較大
			
			if (k[x]==0){
				q.push(x);
			}
		}
	}
	
	// output
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	
    return 0;
}