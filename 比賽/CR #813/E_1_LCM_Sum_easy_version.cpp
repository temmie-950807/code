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
int t, l, r;

// function
int lcm(int x, int y){
    return x*y/__gcd(x, y);
}

int lcm_3(int x, int y, int z){
    return lcm(x, lcm(y, z));
}



signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> l >> r;
        int ans=0;
        
        for (int i=l ; i<=r ; i++){
            for (int j=i+1 ; j<=r ; j++){
                for (int k=j+1 ; k<=r ; k++){
                    if (i<j && j<k && lcm_3(i, j, k)>=i+j+k){
                        cout << i << " " << j << " " << k << " | " << lcm_3(i, j, k) << "\n";
                        ans++;
                    }
                }
            }
        }
        cout << "ans: " << ans << "\n\n";
        
    }
    return 0;
}