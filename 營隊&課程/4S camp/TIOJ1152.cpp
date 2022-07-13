#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int n, tmp;
int a=-1, b=-1; // a=長度, b=星球
vector<int> tree[MAX_SIZE], pass(MAX_SIZE, 0);

void DFS(int n, int len){
	pass[n] = 1;
	
	if (len>a){
		a = len;
		b = n;
	}
	
	for (auto x : tree[n]){
		if (pass[x]==0) DFS(x, len+1);
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		while (cin >> tmp && tmp!=-1){
			tree[i].emplace_back(tmp);
			tree[tmp].emplace_back(i);
		}
	}
	
	// DFS
	DFS(0, 0);
	fill(pass.begin(), pass.end(), 0);
	DFS(b, 0);
	
	// output
	cout << a << "\n";
    return 0;
}