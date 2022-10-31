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
int n, tmp, cnt;
vector<int> v;
vector<pair<int, int>> ans;

void solve(){
    // init
    cnt=0;
    v.clear();
    ans.clear();

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // process
    if (v[0]%2==1 && v[n-1]%2==1){
        for (int i=n-2 ; i>=0 ; i--){
            if (v[i]!=v[n-1] && v[i]%2==1){
                ans.push_back({n-1, i});
                v[i]=v[n-1];
            }
        }
        for (int i=0 ; i<n ; i++){
            if (v[i]!=v[0] && v[i]%2==0){
                ans.push_back({0, i});
                v[i]=v[0];
            }
        }
    }
    if (v[0]%2==0 && v[n-1]%2==0){
        for (int i=n-2 ; i>=0 ; i--){
            if (v[i]!=v[n-1] && v[i]%2==0){
                ans.push_back({n-1, i});
                v[i]=v[n-1];
            }
        }
        for (int i=0 ; i<n ; i++){
            if (v[i]!=v[0] && v[i]%2==1){
                ans.push_back({0, i});
                v[i]=v[0];
            }
        }
    }
    if (v[0]%2==0 && v[n-1]%2==1){
        for (int i=1 ; i<n ; i++){
            if (v[i]!=v[0] && v[i]%2==1){
                ans.push_back({0, i});
                v[i]=v[0];
            }
        }
        for (int i=n-2 ; i>=0 ; i--){
            if (v[i]!=v[n-1] && v[i]%2==0){
                ans.push_back({n-1, i});
                v[i]=v[n-1];
            }
        }
    }
    if (v[0]%2==1 && v[n-1]%2==0){
        for (int i=1 ; i<n ; i++){
            if (v[i]!=v[0] && v[i]%2==0){
                ans.push_back({0, i});
                v[i]=v[0];
            }
        }
        for (int i=n-2 ; i>=0 ; i--){
            if (v[i]!=v[n-1] && v[i]%2==1){
                ans.push_back({n-1, i});
                v[i]=v[n-1];
            }
        }
    }

    // output
    cout << ans.size() << endl;
    for (auto x : ans){
        if (x.first+1<x.second+1) cout << x.first+1 << " " << x.second+1 << endl;
        else cout << x.second+1 << " " << x.first+1 << endl;
    }
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