#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, ans=0, k=-INF;
vector<int> v;

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // process
    int s=0;
    for (int i=0 ; i<n ; i++){
        s += v[i];
        if (s<0) s=0;
        if (v[i]<=0) k=max(k, v[i]);
        ans=max(ans, s);
    }

    // output
    if (ans==0) cout << k << "\n";
    else cout << ans << "\n";
    return 0;
}