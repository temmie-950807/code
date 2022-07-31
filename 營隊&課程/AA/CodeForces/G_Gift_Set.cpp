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
int t, x, y, a, b, ans, last=0;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        ans = 0;
        last = 0;

        // input
        cin >> x >> y >> a >> b;
        int l=0, r=min(x/a, y/b);
        if (l>r) swap(l, r);
        r += 1;

        // binary search
        while (l<r){
            int mid = l+(r-l)/2; // 搜尋用(a, b)分組的個數
            int get_x = mid*a, get_y = mid*b;
            cout << "mid: " << mid << "\n";

            if (get_x > x || get_y > y){
                r = mid;
                last = 0;
            }else{
                int get = min((x-get_x)/b, (y-get_y)/a); // 剩餘的用(b, a)分組的個數
                int k = (x-get_x)-(b*get) + (y-get_y)-(a*get); // 剩餘的糖果
                ans = max(ans, get+mid);

                if (k > last){ // 剩更多了 策略不對
                    r = mid;
                }else{        // 策略正確
                    l = mid+1;
                }
                last = k;
            }
            cout << "l: " << l << " r: " << r << "\n\n";
        }

        // output
        cout << ans << "\n";
    }
    return 0;
}