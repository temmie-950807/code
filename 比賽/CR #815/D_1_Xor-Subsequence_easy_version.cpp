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
const int CHECK=512;
int t, n, tmp;
vector<int> v, dp(1);

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        v.clear();
        dp.resize(1, 0);
        
        // input
        cin >> n;
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        int bst=0;
        for (int i=0 ; i<n ; i++){ // dp_i-- (因為是1-based), 是要選第i個在子序列時, 最大的長度
            dp.push_back(1);

            for (int j=i-1 ; j>=max(0LL, i-CHECK) ; j--){

                // 在這裡, b_p=i, b_{p+1}=j

                if ((v[i]^j) > (v[j]^i)){
                    dp.back()=max(dp.back(), dp[j+1]+1);
                    // 這段是尋找前面最大的序列
                    // index裡的+1是因為1-based, 最後的+1是因為長度增加
                }
            }
            bst=max(bst, dp.back()); // 紀錄最長的子序列
        }

        cout << bst << "\n";
    }
    return 0;
}