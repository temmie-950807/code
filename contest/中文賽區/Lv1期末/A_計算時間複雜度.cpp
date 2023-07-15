#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int ans=0;
string s;
stack<int> sta;

signed main(void){
    fastio;
    
    for (int i=0 ; i<5 ; i++){
        getline(cin, s);
    }

    getline(cin, s);
    for (int i=0 ; i<s.size() ; i++){
        if (s[i]=='{'){
            sta.push(0);
        }else if (s[i]=='}'){
            ans=max(ans, (int)sta.size());
            sta.pop();
        }
    }

    if (ans==0){
        cout << "Theta(1)\n";
    }else{
        cout << "Theta(n^" << ans << ")";
    }
    return 0;
}