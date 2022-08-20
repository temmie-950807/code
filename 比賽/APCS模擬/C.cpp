#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a, b, c, t, ans=0;
vector<int> k, node(200000+5, -1), G[200000+5];
queue<pair<int, int>> q;

void BFS(int now, int t){
    // init
    while (q.size())q.pop();
    
    // main
    q.push({now, 0});
    while (q.size()){
        now=q.front().first;
        t=q.front().second; // time
        q.pop();

        if (node[now]==-1){
            node[now]=t;
        }else{
            node[now]=min(node[now], t);
        }

        for (int i=0 ; i<G[now].size() ; i++){
            if (node[G[now][i]]==-1){
                q.emplace(G[now][i], t+1);
            }else{
                if (node[G[now][i]] > t+1){
                    q.emplace(G[now][i], t+1);
                }
            }
        }
    }
    
}

signed main(void){

    cin >> n >> m;
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for (int i=0 ; i<m ; i++){
        cin >> c;
        k.emplace_back(c);
        node[c]=0;
    }

    // BFS
    for (int i=0 ; i<m ; i++){
        BFS(k[i], 0);
    }

    // output
    for (int i=1 ; i<=n ; i++){
        cout << node[i] << " ";
    }   cout << "\n";
    for (int i=1 ; i<=n ; i++){
        ans+=node[i];
    }
    cout << ans << "\n";

    return 0;
}