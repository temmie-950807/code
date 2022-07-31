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
int n, mid, ans=INF;

signed main(void){
    fastio;
    
    cin >> n;

    int l=1, r=n*n+1;
    while (l<r){
        mid = (l+r)/2;
        int s=0;

        for (int i=1 ; i<=n ; i++){
            s += min(n, mid/i);
        }


        if (s >= n*n/2+1){
            r = mid;
            ans = min(ans, mid);
        }else if (s < n*n/2+1){
            l = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}