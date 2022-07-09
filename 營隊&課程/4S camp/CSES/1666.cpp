#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

// declare
int n, m;
int a, b;
vector<int> output, vis(MAX_SIZE, 1), G[MAX_SIZE];

// function
void dfs(int x){
    vis[x] = 0;

    for (auto k : G[x]){
        if (vis[k]==1){
            dfs(k);
        }
    }
}

signed main(void){
	fastio;
	
    // input&init
    cin >> n >> m;
    vis[0] = 0;

    // make graph
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // DFS
    for (int i=1 ; i<=n ; i++){
        if (vis[i]==1){
            output.push_back(i);
            dfs(i);
        }
    }

    // output
    cout << output.size()-1 << "\n";
    for (int i=0 ; i<output.size()-1 ; i++){
        cout << output[i] << " " << output[i+1] << "\n";
    }
    return 0;
}