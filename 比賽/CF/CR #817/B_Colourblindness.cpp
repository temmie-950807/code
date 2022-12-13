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
int t, n;
string s1, s2;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        bool check=1;

        // input
        cin >> n;
        cin >> s1 >> s2;

        for (int i=0 ; i<n ; i++){
            if ((s1[i]=='R' && s2[i]!='R') || (s1[i]!='R' && s2[i]=='R')){
                cout << "NO\n";
                check=0;
                break;
            }
        }
        
        if (check) cout << "YES\n";
        
    }
    return 0;
}