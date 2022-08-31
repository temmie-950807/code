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
int n, tmp;
vector<int> v(1), p;
multiset<int> ma;
set<int> s={0};

signed main(void){
    fastio;
    
    // input
    cin >> n;
    s.insert(n+1);
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    partial_sum(v.begin(), v.end(), v.begin());
    ma.insert(v[n]);
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        p.emplace_back(tmp);
    }

    // process
    for (int i=0 ; i<n ; i++){
        auto it=s.insert(p[i]).first;
        auto e=ma.find(v[*next(it)-1]-v[*prev(it)]);

        ma.erase(e);
        ma.insert(v[*next(it)-1]-v[*it]);
        ma.insert(v[*it-1]-v[*prev(it)]);

        // output
        cout << *ma.rbegin() << "\n";

        // cout << "set: ";
        // for (auto x : s){
        //     cout << x << " ";
        // }   cout << "\n";
        // cout << "ma: ";
        // for (auto x : ma){
        //     cout << x << " ";
        // }   cout << "\n";

        // cout << "\n\n";
    }
    return 0;
}