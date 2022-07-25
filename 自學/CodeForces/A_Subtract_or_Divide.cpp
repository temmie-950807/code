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
int t, n, tmp;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // input
        cin >> n;
        if (n==1){
            cout << 0 << "\n";
        }else if (n==2){
            cout << 1 << "\n";
        }else if (n==3 || n%2==0){
            cout << 2 << "\n";
        }else{
            cout << 3 << "\n";
        }
        
    }
    return 0;
}