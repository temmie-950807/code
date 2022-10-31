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
int n, tmp, ans;
vector<int> a[2];
bool now;

void solve(){
    // init
    a[0].clear();
    a[1].clear();
    now=0;
    ans=0;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        a[0].push_back(tmp);
    }

    while (a[0].size()!=1 && a[1].size()!=1){
        a[1-now].clear();

        // process
        for (int i=0 ; i<a[now].size()/2 ; i++){
            if (abs(a[now][2*i]-a[now][2*i+1])!=1){
                cout << -1 << endl;
                return;
            }else{
                if (a[now][2*i]>a[now][2*i+1]){
                    ans++;
                }
                a[1-now].push_back(max(a[now][2*i], a[now][2*i+1])/2);
            }
        }

        now=1-now;
    }
    
    // output
    cout << ans << endl;
    return;
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