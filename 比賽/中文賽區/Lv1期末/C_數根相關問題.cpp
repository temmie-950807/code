#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 6e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, k, tmp, ans=-INF;
priority_queue<int> pq;

signed main(void){
    fastio;
    
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    while (k>0 && !pq.empty()){
        int now=pq.top();
        pq.pop();

        tmp=now;
        int total=0;

        while (now>0){
            total+=now%10;
            now/=10;
        }
        
        if (tmp==total){
            ans=max(ans, tmp);
        }else{
            pq.push(total);
        }

        k--;
    }

    if (pq.empty()){
        cout << ans << "\n";
    }else{
        cout << max(ans, pq.top()) << "\n";
    }
    
    return 0;
}