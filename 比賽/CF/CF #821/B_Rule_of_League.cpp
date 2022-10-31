#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, x, y, k;

void solve(){
    // input
    cin >> n >> x >> y;

    if ((x==0 && y==0) || (x!=0 && y!=0)){
        cout << -1 << endl;
        return;
    }else{
        if (x!=0 && (n-1)%x==0){
            k=x;
        }else if (y!=0 && (n-1)%y==0){
            k=y;
        }else{
            cout << -1 << endl;
            return;
        }

        // output
        int now=2, cnt=0;
        for (int i=1 ; i<=n-1 ; i++){
            if (cnt==k){
                now+=k;
                cout << now << " ";
                cnt=1;
            }else{
                cout << now << " ";
                cnt++;
            }
        }
        cout << endl;
    }
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}