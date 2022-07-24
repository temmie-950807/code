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
vector<int> dsu, sz; // dsu[i] = 第i個點的父節點
int t, n, tmp;

void initDSU(){
	dsu.resize(n+1);
	for (int i=1 ; i<=n ; i++) dsu[i]=i; // 每個點都是自己的祖先
}

int findDSU(int x){
	if (dsu[x] != x) dsu[x] = findDSU(dsu[x]); // 找到根節點
	else return dsu[x];
}

void unionDSU(int x, int y){
	x = findDSU(x);
	y = findDSU(y);

	if (x==y) return; // 如果同根就不需要換
	if (sz[x]<sz[y]) swap(x, y);
	dsu[y] = x;       // 大的當根(為了保持平衡)
	sz[x] += sz[y];
}

signed main(void){
	fastio;
	
	// input
	
    return 0;
}