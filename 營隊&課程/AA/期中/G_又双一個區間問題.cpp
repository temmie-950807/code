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
int n, q, a, b;
vector<pair<int, int>> range;

// function
int f(int x){ // 需要的線段數量
    int now=-INF, ret=0;
    for (int i=0 ; i<n ; i++){
        if (range[i].second-x > now){ // 如果一條線段(mid/x)蓋不住, 那麼就新增一條(ret++), 並且重新設開頭
            ret++;
            now = range[i].first;
        }
    }

    return ret;
}

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        range.push_back({b, a});
    }
    sort(range.begin(), range.end());

    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a;

        // binary search
        int l=0, r=1e18;
        while (l<r){
            int mid=(l+r)/2;
            if (f(mid) <= a) r=mid; // 如果線段數過小, 就往上找
            else l=mid+1;           // 反之
        }
        cout << l << "\n";
    }
    return 0;
}