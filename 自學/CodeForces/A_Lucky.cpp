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

// declare
int t;
string s;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> s;
        if (s[0]+s[1]+s[2] == s[3]+s[4]+s[5]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
    return 0;
}