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
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, m;
int tmp, fi=0, se=0;
vector<int> v(1), k;
vector<int> vis(MAX_SIZE, 0);

void solve(){
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    int now=1;
    for (int i=0 ; i<2*n ; i++){
        if (vis[now]==0){
            vis[now]=1;
            fi++;
        }else if (vis[now]==1){
            k.push_back(now);
            vis[now]=2;
            fi--;
        }else{
            break;
        }

        now=v[now];
    }

    // for (auto x : k){
    //     cout << x << " ";
    // }   cout << endl;
    cout << k[(m-fi-1)%k.size()] << endl;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}