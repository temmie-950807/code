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
int n, s=0, tmp, x, output=0;
vector<int> v(MAX_SIZE);

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        s += tmp;
        v[i] = tmp;
    }
    cin >> x;

    // pre-process
    partial_sum(v.begin(), v.end(), v.begin());

    // process
    output += (x/s)*n;
    x %= s;
    output += upper_bound(v.begin(), v.end(), x)-v.begin()+1;

    // output
    cout << output << "\n";
    return 0;
}