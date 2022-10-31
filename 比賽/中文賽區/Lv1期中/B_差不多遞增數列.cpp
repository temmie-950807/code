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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, cnt=0;
vector<int> v;

// function
void f(vector<int> g, int k, int p){ // 最後出現的新號碼, 長度
    if (p==n){
        for (auto x : g){
            cout << x << " ";
        }   cout << "\n";
        cnt++;
    }else{
        g.push_back(0);
        for (int i=1 ; i<=k ; i++){
            g[g.size()-1]=i;
            f(g, k, p+1);
        }
        g[g.size()-1]=k+1;
        f(g, k+1, p+1);
    }
}

signed main(void){
    fastio;
    
    cin >> n;
    f(v, 0, 0);

    // output-cnt
    cout << cnt << "\n";
    return 0;
}