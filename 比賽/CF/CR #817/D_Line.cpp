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
int t, n, ans;
string s;
priority_queue<int> pq;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        while (pq.size()) pq.pop();
        ans=0;

        // input
        cin >> n >> s;
        for (int i=0 ; i<n ; i++){
            if (s[i]=='L'){
                ans+=i;
                if (n-i-1>i){
                    pq.push(n-i-1-i);
                }
            }else{
                ans+=n-i-1;
                if (n-i-1<i){
                    pq.push(i-n+i+1);
                }
            }

        }
        
        // output
        for (int i=0 ; i<n ; i++){
            if (pq.size()){
                ans+=pq.top();
                pq.pop();
            }
            cout << ans << " ";
        }
        cout << "\n";
        
    }
    return 0;
}