#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int t, n, tmp, k;
vector<int> v(MAX_SIZE);
set<int> ans;

signed main(void){
    fastio;

    // init
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(1, (1<<31-1));
    
    cin >> t;
    while (t--){
        // init
        k=0;
        fill(v.begin(), v.end(), 0);
        ans.clear();

        // input
        cin >> n;
        while (ans.size()<n-1){
            tmp=distr(eng);

            auto pp=ans.insert(tmp);
            if (pp.second==1){
                k^=tmp;
            }
        }
        ans.insert(k);

        for (auto x : ans){
            cout << x << " ";
        }   cout << "\n";
        
        cout << "\n";
    }
    return 0;
}