#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e4+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, m, tmp;
vector<int> v(MAX_SIZE, -1), dsu(MAX_SIZE), sz(MAX_SIZE, 1);

int dsu_find(int x){
    while (dsu[x]!=x){
        x=dsu[x];
    }
    return x;
}

void dsu_union(int x, int y){
    int A=dsu_find(x);
    int B=dsu_find(y);

    if (A!=B){
        dsu[A]=dsu[B];
        sz[B]+=sz[A];
    }
}

signed main(void){
    fastio;

    // init
    for (int i=0 ; i<MAX_SIZE ; i++){
        dsu[i]=i;
    }
    
    // input
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v[i]=tmp;
    }

    // union
    for (int i=1 ; i<n ; i++){
        if (v[i]==1 && v[i+1]==1){

        }
    }


    for (int i=1 ; i<=m ; i++){
        cin >> tmp;
    }
    return 0;
}