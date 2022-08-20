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
int t, a, b, c, d;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> a >> b >> c >> d;

        if (a==0 && c==0) cout << "0\n";
        else if (a==0 || c==0) cout <<  "1\n";
        else{
            int A=a*d, B=b*c, C=__gcd(A, B);
            A/=C;
            B/=C;

            if (A==B) cout << "0\n";
            else if (A>1 && B>1) cout << "2\n";
            else cout << "1\n";
        }
        
        
    }
    return 0;
}