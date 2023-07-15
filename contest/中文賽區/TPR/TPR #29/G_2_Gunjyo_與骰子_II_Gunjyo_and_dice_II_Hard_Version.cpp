#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, x;
vector<int> v, ans(MAX_SIZE);

// function
void dfs(int now, int cnt, int total){
    if (cnt==n){
        ans[total]++;
        return;
    }else{
        dfs(0, cnt+1, total+v[0]);
        dfs(1, cnt+1, total+v[1]);
        dfs(2, cnt+1, total+v[2]);
    }
}

void solve(){
    cin >> n;
    for (int i=0 ; i<3 ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    dfs(0, 1, v[0]);
    dfs(1, 1, v[1]);
    dfs(2, 1, v[2]);

    partial_sum(ans.begin(), ans.end(), ans.begin());

    cin >> x;
    for (int i=0 ; i<x ; i++){
        cin >> tmp;
        cout << ans[tmp] << endl;
    }
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}