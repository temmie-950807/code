#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, item, tmp;
int l=1, r, ans=INF, ma=-INF;
vector<int> v;

signed main(void){
    fastio;
    
    cin >> n >> item;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        ma = max(ma, tmp);
        v.push_back(tmp);
    }
    r = (item/n+1)*(ma+1);

    // binary search
    while (l<r){
        int mid=(l+r)/2, s=0;
        for (auto x : v){
            s += mid/x;
        }


        // check
        if (s >= item){
            ans = min(ans, mid);
            r = mid;
        }else{
            l = mid+1;
        }
    }

    // output
    cout << ans << "\n";
    return 0;
}