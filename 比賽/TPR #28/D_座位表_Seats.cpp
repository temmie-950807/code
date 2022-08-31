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
int n, m, t, tmp;
string s;

vector<int> v(1);
map<string, int> ma;

signed main(void){
    fastio;
    
    cin >> n >> m >> t;
    for (int i=0 ; i<n ; i++){
        cin >> s >> tmp;
        ma[s]=tmp;
    }

    for (int i=0 ; i<m ; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    partial_sum(v.begin(), v.end(), v.begin());
    
    for (int i=0 ; i<t ; i++){
        cin >> s;
        if (ma.find(s)==ma.end()) cout << "0\n";
        else{
            cout << lower_bound(v.begin(), v.end(), ma[s])-v.begin() << "\n";
        }
    }
    
    return 0;
}