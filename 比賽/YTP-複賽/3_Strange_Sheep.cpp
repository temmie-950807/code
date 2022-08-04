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
int n, tmp;
vector<int> v;

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // two pointers
    int p1=0, p2=-1, k=1, ans=-INF;
    for (p1 ; p1<n ; p1++){
        while (p2<n-1 && v[p2+1]>=k){
            p2++;
            k++;
        }
        
        // cout << "p1: " << p1 << " p2: " << p2 << " ans: " << ans << "\n";
        ans = max(ans, p2-p1+1);
        k--;
    }

    // output
    cout << ans << "\n";
    return 0;
}