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
int n, tmp, s, a, b;
vector<pair<int, int>> v; // <val, idx>
vector<int> ans(MAX_SIZE);

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        s+=tmp;
        b+=tmp;
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());

    for (int i=0 ; i<n ; i++){
        // init
        b-=v[i].first;

        // get total
        int total=s-v[i].first + v[i].first*(n-1); // 後面;
        total+=i*v[i].first-a; // 前面-前面
        total+=b-(n-i-1)*v[i].first; // 前面-後面

        // final
        a+=v[i].first;
        ans[v[i].second]=total;
    }

    // output
    for (int i=0 ; i<n ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}