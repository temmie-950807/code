#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=3e5;

int n, tmp;
vector<int> v(1);
vector<vector<int>> G(MAX_N);
bitset<2*MAX_N> vis;

void dfs(int now, int pre, int dis){
    vis[dis]=1;

    for (auto x : G[now]){
        if (x!=pre){
            dfs(x, now, dis+v[x]);
        }
    }
}

int dfs2(int now, int pre){
    int ret=0;

    for (auto x : G[now]){
        if (x!=pre){
            ret=max(ret, dfs2(x, now));
        }
    }

    return ret+1;
}

void solve1(){
    for (int i=1 ; i<=n ; i++){
        dfs(i, 0, v[i]);
    }

    for (int i=1 ; i<=2*n ; i++){
        if (vis[i]==0){
            cout << i << "\n";
            return;
        }
    }
}

void solve2(){
    int res=dfs2(1, 0);
    cout << res*2 << "\n";
}

void solve3(){
    bitset<2*MAX_N> ans, ss;
    ss[0]=1;

    for (int i=1 ; i<=n ; i++){
        ss<<=v[i];
        ss[0]=1;
        ans|=ss;
    }

    for (int i=1 ; i<=2*n ; i++){
        if (ans[i]==0){
            cout << i << "\n";
            return;
        }
    }
}

signed main(void){

    fastio;

    int t=1;
    while (t--){

        // input
        bool flag=1;
        cin >> n;
        for (int i=1 ; i<=n ; i++){
            cin >> tmp;
            if (tmp!=(2-(i==1))) flag=0;
            v.push_back(tmp);
        }
        for (int i=1 ; i<n ; i++){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        if (n<=2000){
            solve1();
        }else if (flag){
            solve2();
        }else{
            solve3();
        }
    }

    return 0;
}