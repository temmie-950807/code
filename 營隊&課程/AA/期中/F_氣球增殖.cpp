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
int t, n, xa, xb, ya, yb;

// function
char f(int g, int x, int y){
    if (g==0) return 'R';             // t=0時, 初始值為R
    if (x%2==0 && y%2==0) return 'B'; // 如果x, y | 2 就必定是B
    return f(g-1, (x+1)/2, (y+1)/2);  // 往下遞推
}

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> n >> xa >> ya >> xb >> yb;
        for (int i=xa ; i<=xb ; i++){
            for (int j=ya ; j<=yb ; j++){
                cout << f(n, j, i);
            }
            cout << "\n";
        }
        
    }
    return 0;
}