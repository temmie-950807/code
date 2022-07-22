#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, a, b, w, output=0, f;
vector<pair<int, int>> G[MAX_SIZE];

// function
void dfs(int now, int len, int p){
    if (len>output){
        output = len;
        f = now;
    }

    for (auto x : G[now]){
        if (x.first==p) continue;
        dfs(x.first, len+x.second, now);
    }
}

signed main(void){
	fastio;
	
    while (cin >> n && n!=0){
        // init
        fill(G, G+MAX_SIZE, vector<pair<int, int>>());
        output = 0;
        f = 0;


        // input
        for (int i=0 ; i<n-1 ; i++){
            cin >> a >> b >> w;
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }

        // DFS
        dfs(1, 0, 1);
        dfs(f, 0, f);

        // output
        cout << output << "\n";
    }

    return 0;
}