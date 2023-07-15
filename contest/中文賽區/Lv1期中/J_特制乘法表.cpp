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
int n, q, tmp;

signed main(void){
    fastio;
    
    cin >> n >> q;
    for (int i=0 ; i<q ; i++){
        cin >> tmp;
        tmp = n*n+1-tmp; // 轉換成第k小問題

        int l=1, r=n*n*(n+1); // r是最大範圍n*n*(n+1)
        while (l<r){
            int mid=(l+r)/2;
            int num=0;

            for (int j=1 ; j<=n ; j++){ // 枚舉行
                num += min(mid/(j*(j+1)), n); // 計算比選擇數(mid)還要小的個數, i=mid/(j*(j+1))
            }

            if (num >= tmp) r=mid; // 太多
            else l=mid+1;          // 反之
        }

        cout << l << "\n";
    }
    return 0;
}