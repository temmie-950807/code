#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e4+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, ans=0;
vector<int> v(MAX_SIZE, 0);

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v[i] = tmp;
    }

    // 枚舉 i k
    for (int i=1 ; i<=n ; i++){
        int j=i+1;
        for (int k=i+2 ; k<=n ; k++){
            int s = (v[k]+v[i])/2;
            while (v[j]<=s && j+1<k){
                j++;
            }

            if (v[k]-v[j]<v[j]-v[i]){
                // cout << v[i] << " " << v[j] << " " << v[k] << "\n";
                ans += k-j;
            }
        }
    }

    // output
    cout << ans << "\n";
    return 0;
}