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
int task, n, m, xa, ya, xb, yb, xc, yc, xd, yd;
struct place{
    int x;
    int y;
};

signed main(void){
    fastio;
    
    cin >> task;
    while (task--){
        cin >> n >> m >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        place A={xa, ya};
        place B={xb, yb};
        place C={xc, yc};
        place D={xd, yd};
        int ans=0, check=0;

        // check of x
        if ((A.x <= C.x && C.x <= B.x) || (A.x <= D.x && D.x <= B.x) || (C.x <= A.x && A.x <= D.x) || (C.x <= B.x && B.x <= D.x)) check=1;

        ans += check*(min(C.x, D.x)-max(A.x, B.x)+1);

        // output
        cout << ans << "\n";
    }
    return 0;
}