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
int n, tmp, ma=-INF, gg;
int pre[2005][2005];
vector<int> v;

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for (int i=0 ; i<n ; i++){
        gg=v[i];
        for (int j=i ; j<n ; j++){
            gg=__gcd(gg, v[j]);
            pre[i][j]=gg;
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            // i跟j是要刪掉的值

            // init
            gg=-INF;

            if (i>=1){
                if (gg==-INF){
                    gg=pre[0][i-1];
                }else{
                    gg=__gcd(gg, pre[0][i-1]);
                }
            }

            if (j-i>=2){
                if (gg==-INF){
                    gg=pre[i+1][j-1];
                }else{
                    gg=__gcd(gg, pre[i+1][j-1]);
                }
            }

            if (j<=n-1){
                if (gg==-INF){
                    gg=pre[j+1][n-1];
                }else{
                    gg=__gcd(gg, pre[j+1][n-1]);
                }
            }

            ma=max(ma, gg);
        }
    }

    // output
    cout << ma << "\n";
    return 0;
}