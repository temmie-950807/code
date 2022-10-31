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
int t, n, tmp, ans;
stack<int> sta;
vector<int> k(MAX_SIZE);

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        ans=0;
        fill(k.begin(), k.end(), 0);
        while (sta.size()) sta.pop();

        // input
        cin >> n;
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            if (k[tmp]==1) tmp=0;

            while (!sta.empty() && sta.top()>tmp){
                while (sta.size()){ // 清空
                    if (k[sta.top()]==0){
                        ans++;
                        k[sta.top()]=1;
                    }
                    sta.pop();
                }

            }
            
            if (tmp!=0) sta.push(tmp);
        }

        // output
        cout << ans << "\n";
        
    }
    return 0;
}