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
string s;

void solve(){
    cin >> s;
    if (s=="0") cout << 0 << endl;
    int pre=0;
    
    for (int i=0 ; i<s.size() ; i++){
        if (s[i]!='0' && s[i]!='.'){
            pre=1;
        }

        if (pre==1 && s[i]!='.'){
            cout << s[i];
        }
    }
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}