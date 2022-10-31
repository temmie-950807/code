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
int n, tmp, ans, block;
vector<int> cnt(MAX_SIZE);

void solve(){
    // init
    ans=0;
    fill(cnt.begin(), cnt.end(), 0);
    block=0;

    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        if (i-tmp>block){
            block=i-tmp;
        }
        cnt[block+1]++;
    }

    // for (int i=1 ; i<10 ; i++){
    //     cout << cnt[i] << " ";
    // }   cout << endl;

    for (int i=1 ; i<=n ; i++){
        ans+=cnt[i];
        cnt[i+1]+=max(0LL, cnt[i]-1);
        cnt[i]=0;

        // for (int i=1 ; i<10 ; i++){
        // cout << cnt[i] << " ";
        // }   cout << endl;
    }

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