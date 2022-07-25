#include <exts/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, tmp;
vector<int> v(MAX_SIZE, 0);

signed main(void){
    fastio;
    
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v[tmp] = 1;
    }

    for (int i=1 ; i<=n ; i++){
        if (v[i] == 0){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}