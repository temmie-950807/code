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
int n, tmp, total, ans;
vector<int> v, k;

void solve(){
    // init
    v.resize(1, 0);
    k.resize(1, 0);
    total=0;
    ans=INF;

    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        total+=tmp;
        v.push_back(tmp);
        k.push_back(tmp+k[i-1]);
    }

    // process
    for (int i=1 ; i<=n ; i++){
        if (total%k[i]==0){
            // 往下找
            int tmp_ans=i;


            int l=i, r;
            for (r=i+1 ; r<=n ; r++){
                if (k[r]-k[l]==k[i]){
                    tmp_ans=max(tmp_ans, r-l);
                    l=r;
                }else if (k[r]-k[l]>k[i]){
                    break;
                }
            }

            if (r!=n+1){
                continue;
            }else{
                ans=min(ans, tmp_ans);
            }
        }
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