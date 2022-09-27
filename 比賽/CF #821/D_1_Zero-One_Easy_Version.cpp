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
int n, x, y;
int cnt;
bool check;
string s1, s2;

void solve(){
    // init
    cnt=0;
    check=0;

    // input
    cin >> n >> x >> y >> s1 >> s2;

    for (int i=0 ; i<n;  i++){
        s1[i]^=s2[i];
        cnt+=s1[i];
    }

    // check
    if (cnt%2==1){
        cout << -1 << endl;
        return;
    }

    // check connect 
    for (int i=1 ; i<n ; i++){
        if (s1[i]==1 && s1[i-1]==1){
            check=1;
            break;
        }
    }

    // get answer
    if (cnt==2){
        if (check){
            cout << min(x, 2*y) << endl;
        }else{
            cout << y << endl;
        }
    }else{
        cout << cnt/2*y << endl;
    }
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