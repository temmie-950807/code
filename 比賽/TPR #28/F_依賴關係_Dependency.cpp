#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 3000+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, i;
vector<int> G[MAX_SIZE];
set<int> s;
bitset<MAX_SIZE> vis;

void dfs(int now){
    vis[now]=1;
    if (now!=i) s.insert(now);

    for (auto x : G[now]){
        if (vis[x]==0){
            dfs(x);
        }
    }
}

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (i=1 ; i<=n ; i++){
        while (cin >> tmp && tmp!=0){
            G[i].emplace_back(tmp);
        }
    }

    for (i=1 ; i<=n ; i++){
        // init
        vis=0;
        s.clear();

        // dfs
        dfs(i);

        // output
        cout << s.size() << "\n";
        for (auto x : s){
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}