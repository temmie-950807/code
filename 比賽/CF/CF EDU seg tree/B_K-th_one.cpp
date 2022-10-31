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
int n, m, tmp;
int a, b;
vector<int> v(MAX_SIZE);
order_set s;

signed main(void){
    fastio;
    
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;

        v[i]=tmp;
        if (tmp==1){
            s.insert(i);
        }
    }

    for (int i=0 ; i<m ; i++){
        cin >> a >> b;

        if (a==1){
            if (v[b]==1){
                v[b]=0;
                s.erase(b);
            }else{
                v[b]=1;
                s.insert(b);
            }
        }

        if (a==2){
            cout << *s.find_by_order(b) << "\n";
        }
    }
    return 0;
}