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
vector<int> v, k, BIT(MAX_SIZE, 0);

void update(int idx, int val){
    while (idx<=1e5){
        BIT[idx] += val;
        idx += (idx&-idx);
    }

    return;
}

int query(int idx){
    int ans = 0;
    while (idx>0){
        ans += BIT[idx];
        idx -= (idx&-idx);
    }

    return ans;
}


signed main(void){
    fastio;
    
    while (cin >> t){
        // init
        fill(BIT.begin(), BIT.end(), 0);
        v.clear();
        k.clear();

        // process
        for (int i=0 ; i<t ; i++){
            // input
            cin >> n;
            v.push_back(n);
        }

        k = v;
        sort(k.begin(), k.end());
        k.resize(unique(k.begin(), k.end())-k.begin());

        for (int i=0 ; i<t ; i++){
            int pos = lower_bound(k.begin(), k.end(), v[i])-k.begin()+1;
            update(pos, 1);
            cout << query(1e5)-query(pos)+1 << "\n";
        }

    }
    return 0;
}