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
int t, n, tmp, ans=0, k;
stack<pair<int, int>> sta;

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;

        while (!sta.empty() && tmp>=sta.top().first){
            cout << "add1: " << sta.top().second-k << "\n";
            cout << "add2: " << i-sta.top().second << "\n";
            ans+=sta.top().second-k;
            ans+=i-sta.top().second;
            sta.pop();
        }

        if (sta.size()==0){
            k=i;
        }
        sta.push({tmp, i});
    }

    while (sta.size()){
        ans+=sta.top().second-k;
        cout << "add: " << sta.top().second-k << "\n";
        sta.pop();
    }

    cout << "ans: " <<ans << "\n";
    
    return 0;
}