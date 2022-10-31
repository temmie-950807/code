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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int N, D, A, X, H, attack=0, ans=0;
vector<int> att_times(MAX_SIZE, 0);
vector<pair<int, int>> v;

signed main(void){
    fastio;
    
    // input
    cin >> N >> D >> A;
    for (int i=0 ; i<N ; i++){
        cin >> X >> H;
        v.push_back({X, H});
    }
    sort(v.begin(), v.end());

    // process
    // p, i都是指針, 為v的索引
    int p=0;
    for (int i=0 ; i<N ; i++){
        while (p+1<N && v[p+1].first-v[i].first <= 2*D) p++; // 如果還在攻擊範圍內, 就把p加上(尋找下一個目標是否符合)

        int k = (v[i].second+A-1)/A; // 需要攻擊的次數(ceil)
        if (i > 0) att_times[i] += att_times[i-1]; // 差分 -> 前綴和
        if (att_times[i] < k){ // 如果還需要補攻擊(也就是之前的攻擊不夠), 進入此段
            int v = k - att_times[i]; // 計算有多少攻擊要補
            ans += v; // 紀錄答案

            // 差分
            att_times[i] += v;
            att_times[p+1] -= v;
        }
    }

    // output
    cout << ans << "\n";
    return 0;
}