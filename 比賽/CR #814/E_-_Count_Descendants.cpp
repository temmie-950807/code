#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, q, a, b;
vector<int> G[MAX_SIZE], L(MAX_SIZE), R(MAX_SIZE), tier[MAX_SIZE];
bitset<MAX_SIZE> pass, s;

// function
int id=0;
void DFS(int now, int t){
    L[now]=++id;
    pass[now]=1;
    tier[t].emplace_back(L[now]);

    for (auto x : G[now]){
        if (pass[x]==0) DFS(x, t+1);
    }

    R[now]=id;
}

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=2 ; i<=n ; i++){
        cin >> tmp;
        G[tmp].emplace_back(i);
    }

    // DFS
    DFS(1, 0);

    // query
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b; // 需要包含a, 深度為b;

        if (s[b]==0){
            sort(tier[b].begin(), tier[b].end());
            s[b]=1;
        }
        cout << upper_bound(tier[b].begin(), tier[b].end(), R[a])-lower_bound(tier[b].begin(), tier[b].end(), L[a]) << "\n";
    }
    return 0;
}