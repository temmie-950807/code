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
int t, n, k;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> n >> k;
        
        if (k==0) cout << "NO\n";
        else{
            if (k%2==1){
                cout << "YES\n";
                for (int i=1 ; i<=n ; i+=2){
                    cout << i << " " << i+1 << "\n";
                }
            }else{
                if (k%4==2){
                    cout << "YES\n";
                    for (int i=2 ; i<=n ; i+=2){
                        if (i%4==0){
                            cout << i-1 << " " << i << "\n";
                        }else{
                            cout << i << " " << i-1 << "\n";
                        }
                    }
                }else{
                    cout << "NO\n";
                }
            }
        }
        
    }
    return 0;
}