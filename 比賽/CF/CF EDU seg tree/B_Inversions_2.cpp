#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp;
vector<int> v(MAX_SIZE), ans(MAX_SIZE);
order_set s;

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v[i]=tmp;
        s.insert(i);
    }

    for (int i=n-1 ; i>=0 ; i--){
        int k=*s.find_by_order(i-v[i]);
        s.erase(k);

        ans[i]=k+1;
    }

    for (int i=0 ; i<n ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}