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
const int MAX_INT = 1e9;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int t, n, k, tmp;
vector<int> v1, G[MAX_SIZE];
vector<pair<int, int>> v2; // step1的參照 <value, index>
int ST[20][MAX_SIZE];      // step2的稀疏表

// function
void build() {
    int h = floor(log2(n));

    // base case
    for (int j = 0; j < n; j++) ST[0][j] = v1[j];

    // iterative dynamic programming approach
    for (int i = 1; i <= h; i++) 
        for (int j = 0; j + (1<<i) <= n; j++)
            ST[i][j] = min(ST[i-1][j], ST[i-1][j + (1<<(i-1))]);
}
int query(int l, int r) {        // query in range [l,r)
    int p = 31 - __builtin_clz(r-l);
    return min(ST[p][l], ST[p][r-(1<<p)]);
}

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        v1.clear();
        v2.clear();
        memset(ST, 0, sizeof(ST));
        for (int i=0 ; i<MAX_SIZE ; i++) G[i].clear();

        // input
        cin >> n >> k;
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            v1.emplace_back(tmp);
            v2.emplace_back(tmp, i);
        }
        
        // step1: 替換元素
        sort(v2.begin(), v2.end());
        for (int i=0 ; i<k ; i++){
            v1[v2[i].second] = MAX_INT;
        }
        
        // step2: 稀疏表, 建表
        build();
    }
    return 0;
}