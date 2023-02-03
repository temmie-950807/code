#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

// declare
const int MAX_SIZE = 2e5+5;

int n, m, tmp;
int a, b;
int v[MAX_SIZE], dis[MAX_SIZE];
int mi=MAX_SIZE;
vector<int> G[MAX_SIZE];

void dfs(int now, int pre, int len){
    if (len>=dis[now]){
        return;
    }else if (len>=mi){
        return;
    }else{
        dis[now]=len;
    }

    for (auto x : G[now]){
        if (x==pre) continue;
        else{
            dfs(x, now, len+1);
        }
    }
}

void solve(){
    // input
    cin >> n >> m;

    // init
    mi=MAX_SIZE;
    fill(dis, dis+n+1, MAX_SIZE);
    for (int i=1 ; i<=n ; i++){
        G[i].clear();
    }

    // input
    for (int i=0 ; i<n-1 ; i++){
        cin >> v[i];
    }
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // process
    dfs(m, 0, 0);
    for (int i=0 ; i<n-1 ; i++){
        cout << min(mi, dis[v[i]]) << " ";
        mi=min(mi, dis[v[i]]);
        if (mi!=1){
            dfs(v[i], 0, 0);
        }
    }
    cout << endl;
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}