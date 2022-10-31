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
int n, a, b, c;
vector<pair<int, int>> v; // <pos, color>

void solve(){
    // init
    v.clear();

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b >> c;
        v.push_back({a, c});
        v.push_back({b, c});
    }

    // process
    sort(v.begin(), v.end());
    for (auto x : v){
        cout << x.first << " ";
    }   cout << endl;
    for (auto x : v){
        cout << x.second << " ";
    }   cout << endl;

    cout << endl << "=====" << endl;

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