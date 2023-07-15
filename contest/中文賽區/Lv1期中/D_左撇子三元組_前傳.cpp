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
int n, tmp, ans=0;
vector<int> v(500+5, 0), k(500+5, 0);

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v[tmp]++;
    }

    for (int i=1 ; i<=500 ; i++){
        v[i]--;
        for (int j=1 ; j<=500 ; j++){
            v[j]--;
            for (int k=1 ; k<=500 ; k++){
                v[k]--;
                if (i<=j && j<=k && v[i]>=0 && v[j]>=0 && v[k]>=0 && j-i>k-j){
                    if (j==k){
                        ans += (v[i]+1)*(v[j]+1)*(v[k]+2)/2;
                    }else{
                        ans += (v[i]+1)*(v[j]+1)*(v[k]+1);
                    }
                }
                v[k]++;
            }
            v[j]++;
        }
        v[i]++;
    }

    // output
    cout << ans << "\n";
    return 0;
}