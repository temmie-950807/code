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
int n, ty, val;
multiset<int> s;
map<int, int> cnt;

signed main(void){
    fastio;
    
    cin >> n;
    while (n--){
        // input
        cin >> ty >> val;

        if (ty==1){
            s.insert(val);
            cnt[val]++;
        }else if (ty==2){
            auto it=s.find(val);
            if (it!=s.end()){
                s.erase(it);
                cnt[val]--;
            }
        }else if (ty==3){
            cout << cnt[val] << "\n";
        }
        
        
    }
    return 0;
}