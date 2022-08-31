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
struct Data{
    int dk;
    int dp;
    int dt;
} D;

int n, people=0, reward=0, ma=0;
vector<pair<int, int>> v;

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> D.dk >> D.dp >> D.dt;
        v.push_back({max(1LL, D.dk-D.dp), D.dt}); // 右界
        v.push_back({D.dk+D.dp+1, -D.dt}); // 左界+1
    }
    sort(v.begin(), v.end());

    // process
    for (auto x : v){
        if (x.second>0) people++;
        else people--;
        reward+=x.second;

        // cout << x.first << " " << x.second << "\n";
        // cout << "people: " << people << " reward: " << reward << "\n\n";

        ma=max(ma, reward*people);
    }

    // output
    cout << ma << "\n";

    return 0;
}