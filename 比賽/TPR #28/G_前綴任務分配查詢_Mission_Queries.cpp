#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
struct Data{
    int col;
    int vic;

    bool operator < (const Data A) const{
        return col-vic>A.col-A.vic;
    }
} D;

int n, q, k;
int a, b, tmp;
vector<Data> v;
vector<pair<int, int>> query, ans;
multiset<Data> s1, s2;

signed main(void){
    fastio;
    
    // input
    cin >> n >> q >> k;
    for (int i=0 ; i<n ; i++){
        cin >> D.col >> D.vic;
        v.emplace_back(D);
    }

    for (int i=0 ; i<q ; i++){
        cin >> tmp;
        query.emplace_back(tmp, i);
    }
    sort(query.begin(), query.end());

    int i=0, colten_sum=0, victor_sum=0;
    for (auto x : query){
        while (i<x.first){
            s1.insert(v[i]);

            colten_sum+=v[i].col;

            i++;
        }

        while (s1.size()>k){
            colten_sum-=(*prev(s1.end())).col;
            victor_sum+=(*prev(s1.end())).vic;
            s2.insert(*prev(s1.end()));
            s1.erase(prev(s1.end()));
        }
        
        // get ans
        ans.emplace_back(x.second, colten_sum+victor_sum);

    }

    // output
    sort(ans.begin(), ans.end());
    for (auto x : ans){
        cout << x.second << "\n";
    }
    return 0;
}