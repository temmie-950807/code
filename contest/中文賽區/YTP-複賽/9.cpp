#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, m, tmp, a, b, ans=-INF;
vector<int> val(MAX_SIZE);
vector<int> G[MAX_SIZE], dp[2];

// function
void dfs(int now, int p1, int p2){
    if (p1==-1 && p2==-1){
        dp[0][now] = 0;
        dp[1][now] = val[now];
    }else if (p2==-1){
        dp[0][now] = dp[1][p1];
        dp[1][now] = max(dp[1][p1], val[now]);
    }else{
        dp[0][now] = max(dp[0][p1], dp[1][p1]);
        dp[1][now] = max(dp[0][p1]+val[now], dp[1][p2]+val[now]);
    }
    cout << "now: " << now << " " << dp[0][now] << " | " << dp[1][now] << "\n";
    ans = max({ans, dp[0][now], dp[1][now]});
    for (auto x : G[now]){
        if (x==p1) continue; // 確保不會回朔
        dfs(x, now, p1);
    }
}

signed main(void){
    fastio;
    
    // init
    dp[0] = vector<int>(MAX_SIZE, 0); // 不選取此點
    dp[1] = vector<int>(MAX_SIZE, 0); // 選取此點
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        val[i] = tmp;
    }
    for (int i=1 ; i<=m ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // tree dp
    dfs(1, -1, -1);
    for (int i=1 ; i<=n ; i++) cout << dp[0][i] << " ";
    cout << "\n";
    for (int i=1 ; i<=n ; i++) cout << dp[1][i] << " ";
    cout << "\n";

    // output
    cout << ans << "\n";
    return 0;
}