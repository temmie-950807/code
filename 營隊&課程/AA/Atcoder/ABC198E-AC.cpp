// Problem: E - Unique input
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5

using namespace std;
// using namespace __gnu_pbds;

// declare
int n, c, a, b;
vector<int> input(MAX_SIZE, 0), color(MAX_SIZE, 0), G[MAX_SIZE], output;
bitset<MAX_SIZE> pass;

void DFS(int n){
	pass[n] = 1;
	color[input[n]]++;
	
	// check answer
	if (color[input[n]] == 1){
		output.push_back(n);
	}
	
	// find next
	for (auto x : G[n]){
		if (pass[x] == 0){
			DFS(x);
		}
	}
	
	// final
	pass[n]=0;
	color[input[n]]--;
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=1; i<=n ; i++){
		cin >> c;
		input[i] = c;
	}
	for (int i=1 ; i<n ; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	// DFS
	DFS(1);
	
	// output
	sort(output.begin(), output.end());
	for (auto x : output){
		cout << x << "\n";
	}
    return 0;
}