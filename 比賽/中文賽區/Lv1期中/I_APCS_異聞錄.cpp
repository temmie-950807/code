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
int t, n, a, b;
vector<pair<int, int>> range;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        range.clear();

        // input
        cin >> n;
        for (int i=0 ; i<n ; i++){
            cin >> a >> b;
            range.push_back({a, -b});
        }
        sort(range.begin(), range.end());

        int now=-1, ma=-1, ans=0;
        // now: 目前得覆蓋到的點, ma: 最大的右界, ans: 輸出
        for (int i=0 ; i<n ; i++){
            if (range[i].first > now){ // 超出要覆蓋的範圍
                if (ma > now){         // 如果目前最大值大於要覆蓋的範圍, 採用此段, 並且更新
                    ans++;
                    now=ma;
                }
            }

            if (range[i].first > now){ // 超出要覆蓋的範圍(也就是目前最大的, 代表一段區間的結束)
                ans++;                 // 需要算入最後一段區間
                now=-range[i].second;  // 目前的右界變成新的必須覆蓋的範圍
            }

            ma = max(ma, -range[i].second); // 目前右邊的右界
        }

        if (ma > now) ans++;
        cout << ans << "\n";
    }
    return 0;
}