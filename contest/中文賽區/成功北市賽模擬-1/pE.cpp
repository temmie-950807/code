#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int MAX_N=2e5+5;
const int INF=2e18;

int n, q;
int a, b, c;
int mi;
vector<vector<pair<int, int>>> G(MAX_N);

bool dfs(int now, int pre, int dis){

    if (now==b){
        mi=min(mi, dis);
        return 1;
    }

    for (auto x : G[now]){
        if (x.first!=pre){
            if (dfs(x.first, now, dis+x.second)){
                mi=min(mi, dis);
                return 1;
            }
        }
    }

    return 0;
}

void solve1(){
    
    // input
    cin >> n;
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    // process
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        mi=0;
        dfs(a, 0, 0);
        cout << -mi+1 << "\n";
    }
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}