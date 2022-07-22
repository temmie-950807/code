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
queue<int> q;

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
			q.push(i);
			k[i] = INF;
		}
	}
	
	while (q.size()){
		int now = q.front();
		q.pop();
		
		output.PB(now);
		
		for (auto x : G[now]){
			k[x]--;
			
			if (k[x]==0){
				q.push(x);
				k[x] = INF;
			}
		}
	}
	
	if (output.size()==n){
		for (auto x : output) cout << x << " ";
		cout << "\n";
	}else{
		cout << "IMPOSSIBLE\n";
	}
    return 0;
}