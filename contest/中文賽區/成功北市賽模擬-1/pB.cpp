#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int MAX_N=5e5+5;
const int INF=2e18;

int n, m, s, t, v;
int a, b, c;
vector<vector<pair<int, int>>> G(MAX_N);
vector<int> path, dis(MAX_N, INF);
bitset<MAX_N> vis;

bool dfs1(int now){
    vis[now]=1;
    path.push_back(now);
    if (now==t) return 1;

    for (auto x : G[now]){
        if (vis[x.first]==0){
            if (dfs1(x.first)) return 1;
        }
    }

    path.pop_back();
    return 0;
}

int dfs2(int now){
    vis[now]=1;
    if (now==v) return 0;

    for (auto x : G[now]){
        if (vis[x.first]==0){
            int res=dfs2(x.first);
            if (res!=-1) return res+x.second;
        }
    }

    return -1;
}

void solve1(){

    // input
    cin >> n >> m >> s >> t >> v;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for (int i=1 ; i<=n ; i++){
        sort(G[i].begin(), G[i].end());
    }

    // process
    vis=0;
    dfs1(s);

    for (int i=0 ; i<path.size()-1 ; i++){
        int a=path[i];
        int b=path[i+1];

        auto it1=lower_bound(G[a].begin(), G[a].end(), make_pair(b, -INF));
        it1->second=0;
        auto it2=lower_bound(G[b].begin(), G[b].end(), make_pair(a, -INF));
        it2->second=0;
    }

    // for (int i=1 ; i<=n ; i++){
    //     cerr << "i: " << i << " | ";
    //     for (auto x : G[i]){
    //         cerr << x.first << ", " << x.second << " / ";
    //     }
    //     cerr << "\n";
    // }

    vis=0;
    cout << dfs2(s) << "\n";
    

}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}