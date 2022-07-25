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
int n, q, tmp, a, b, c;
vector<int> v(MAX_SIZE, 0), BIT(MAX_SIZE, 0);

void update(int idx, int val){
    for (int i=idx ; i<MAX_SIZE ; i+=i&-i){
        BIT[i] += val;
    }
    return;
}

int query(int idx){
    int ret=0;
    for (int i=idx ; i>0 ; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

signed main(void){
    fastio;
    
    // input
    cin >> n >> q;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v[i] = tmp;
        update(i, tmp);
    }

    // process
    for (int i=1 ; i<=q ; i++){
        cin >> a >> b >> c;
        if (a==1){
            update(b, c-v[b]);
            v[b] = c;
        }
        if (a==2){
            cout << query(c)-query(b-1) << "\n";
        }
    }
    return 0;
}