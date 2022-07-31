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
int n, k, tmp, ans=0;
vector<int> A, B;

signed main(void){
    fastio;
    
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (auto x : A){
        ans += lower_bound(B.begin(), B.end(), k-x)-B.begin();
    }

    // output
    cout << ans << "\n";
    return 0;
}