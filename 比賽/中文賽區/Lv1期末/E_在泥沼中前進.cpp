#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e3+5;
using namespace std;

// declare
int n, m, ans=0;
int a, b, c;
vector<pair<int, int>> G[MAX_SIZE]; // <goal, k>
bitset<MAX_SIZE> vis;

// function
void dfs(int now, int k){
    vis[now]=1;
    ans++;

    for (auto x : G[now]){
        if (x.second==1) continue;

        if (vis[x.first]==0 && k==0){
            vis[x.first]=1;
            dfs(x.first, 0);
        }else if (vis[x.first]==0 && k==1){
            vis[x.first]=1;
            dfs(x.first, 1);
        }
    }

    for (auto x : G[now]){
        if (x.second==0) continue;

        if (vis[x.first]==0 && k==0){
            vis[x.first]=1;
            dfs(x.first, 1);
        }
    }
}


signed main(void){
    fastio;
    
    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    // process
    for (int i=1 ; i<=n ; i++){
        vis=0;
        vis[i]=1;

        dfs(i, 0);
    }

    // output
    cout << ans << "\n";
    return 0;
}


