#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, a, b;
int f, fl;
vector<int> G[MAX_SIZE];
bitset<MAX_SIZE> vis;

void dfs(int x, int len){
    if (len>fl){
        fl = len;
        f = x;
    }

    vis[x] = 1;
    for (auto y : G[x]){
        if (vis[y] == 0){
            dfs(y, len+1);
        }
    }
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // process
    dfs(1, 0);
    vis = 0;
    dfs(f, 0);

    // output
    cout << fl << "\n";

    return 0;
}