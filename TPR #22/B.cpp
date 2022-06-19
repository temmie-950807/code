// Problem: B. 企鵝的夢想 (Gino's Dream)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N];
int dfn[N], low[N], scc[N], pt[N], inst[N], deg[N], sccid, t;
stack<int> st;
vector<pair<int,int>> edges;

void dfs(int u){
    dfn[u] = low[u] = ++t;
    st.push(u);
    inst[u] = 1;

    for(auto v : adj[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(inst[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u]==dfn[u]){
        int x;
        ++sccid;
        do{
            x = st.top(); st.pop();
            inst[x] = 0;
            scc[x] = sccid;
            pt[sccid] = x;
        }while(x != u);
    }
}

signed main(){
    fastio
    int n, m;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }

    for(int i = 1;i <= n;i++){
        if(!dfn[i]) dfs(i);
    }

    for(auto [u,v] : edges){
        if(scc[u] != scc[v]) deg[scc[v]]++;
    }

    vector<int> ans;

    for(int i = 1;i <= sccid;i++){
        if(deg[i]==0 && pt[i] != 1) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << 1 << " " << pt[x] << "\n";
    }
}