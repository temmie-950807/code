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
int n, tmp;
string a, b;
vector<string> v;

void solve(){
    cin >> a >> b;

    int c, d;
    for (int i=0 ; i<v.size() ; i++){
        if (a==v[i]){
            c=i;
        }
        if (b==v[i]){
            d=i;
        }
    }

    if (c<d) cout << "<" << endl;
    if (c==d) cout << "=" << endl;
    if (c>d) cout << ">" << endl;
    return;
}

signed main(void){
    fastio;

    string k="S";
    for (int i=0 ; i<50 ; i++){
        v.insert(v.begin(), k);
        k="X"+k;
    }
    v.push_back("M");
    k="L";
    for (int i=0 ; i<50 ; i++){
        v.push_back(k);
        k="X"+k;
    }

    // for (auto x : v){
    //     cout << x << endl;
    // }
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}