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
int n, tmp, ca, cb, f;
vector<int> a, b;

void solve(){
    // init
    ca=0;
    cb=0;
    f=0;
    a.clear();
    b.clear();

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        ca+=tmp;
        a.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        b.push_back(tmp);
        cb+=tmp;
        f+=(a[i]!=b[i]);
    }

    // cout << f << " " << ca << " " << cb << endl;
    // cout << "ans: ";
    cout << min(f, abs(cb-ca)+1) << endl;

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