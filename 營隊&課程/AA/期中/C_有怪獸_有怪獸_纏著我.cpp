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
int t, n, tmp_n, k, tmp, ma;
vector<int> v;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        v.clear();
        ma = -INF;

        // input
        cin >> n >> k;
        for (int i=0 ; i<k ; i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        do{
            tmp_n = n;
            for (auto x : v){
                tmp_n *= (100-x);
                tmp_n /= 100;
            }

            ma = max(ma, n-tmp_n);
        } while (next_permutation(v.begin(), v.end()));
        
        
        // output
        cout << ma << "\n";
        
    }
    return 0;
}