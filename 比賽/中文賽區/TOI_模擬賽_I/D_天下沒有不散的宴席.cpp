#include <bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int INF=8e4;
const int MAX_SIZE=5e5+5;
const int MOD=998244353;

// declare
int n, tmp, ans;
vector<int> v, k;
set<int> G[MAX_SIZE];
bitset<20> b;
bitset<MAX_SIZE> vis;

int dfs(int x){
    // cout << "x: " << x << endl;
    int ret=G[x].size();
    vis[x]=1;

    for (auto y : G[x]){
        if (vis[y]==0){
            ret*=dfs(y);
            ret%=MOD;
        }
    }

    return ret;
}

void solve1(){
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        k.push_back(tmp);
    }

    // build graph
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            b=v[i]^v[j];
            if (b.count()<=2){
                G[i].insert(j);
                G[j].insert(i);
            }
        }
    }

    // cout << "=============\n";
    // for (int i=0 ; i<n ; i++){
    //     for (auto x : G[i]){
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "=============\n";

    // queries
    for (auto x : k){
        // init
        vis=0;
        ans=0;

        // DFS
        for (int i=0 ; i<n ; i++){
            if (vis[i]==0){
                int add=dfs(i);
                ans+=add;
                if (ans>=MOD) ans-=MOD;
            }
        }

        // output
        cout << ans << "\n";

        // remove person
        // cout << "remove: " << x-1 << "\n";
        G[x-1].clear();
        for (int i=0 ; i<n ; i++){
            G[i].erase(x-1);
        }
    }
}

signed main(){
    fastio

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}