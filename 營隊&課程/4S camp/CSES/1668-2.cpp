// Problem: Building Teams
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int n, m, a, b;
bool check = 0;
vector<int> G[MAX_SIZE], pass(MAX_SIZE, 0);

// function
void DFS(int n, int s){
	if (check){
		return;
	}else if (pass[n] == 0){
		pass[n] = s;
		
		for (auto x : G[n]){
			DFS(x, 3-s);
		}
	}else if (pass[n] != s){
		check = 1;
		cout << "IMPOSSIBLE\n";
	}else{
		return;
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
	for (int i=0 ; i<m ; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	// DFS
	for (int i=1 ; i<=n ; i++){
		if (pass[i]==0 && check==0){
			DFS(i, 1);
		}
	}
	
	// output
	if (check == 0){
		for (int i=1 ; i<=n ; i++){
			cout << pass[i] << " ";
		}
	}
    return 0;
}