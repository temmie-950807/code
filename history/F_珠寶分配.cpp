#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl "\n"
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define ff first
#define ss second
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define maxn 1200000
#define inf 8e18
#define lowbit(x) ((x)&(-x))
#ifdef DEBUG
bool debug_mode = true;
#else
bool debug_mode = false;
#endif
#define cerr if(debug_mode) cerr
#define dbg(x) cerr << #x << " = " << x << endl
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool vis[maxn];

signed main() {
    int n;
    cin >> n;
    vector<tiii> va, vb;
    for (int i = 0; i < n * 2; i++) {
        int a, b;
        cin >> a >> b;
        va.push_back({a, b * -1, i});
        vb.push_back({b, a * -1, i});
    }
    sort(va.begin(), va.end(), greater<tiii>());
    sort(vb.begin(), vb.end(), greater<tiii>());
    int pa = 0, pb = 0;
    int ansa = 0, ansb = 0;
    // for (auto e : va) cerr << get<2>(e) << " "; cerr << endl;
    // for (auto e : vb) cerr << get<2>(e) << " "; cerr << endl;
    int _ = n;
    while (_--) {
        // select from va
        {
            int a, b, id;
            tie(a, b, id) = va[pa];
            while (vis[id]) {
                pa++;
                tie(a, b, id) = va[pa];
            }
            vis[id] = true;
            ansa += a;
            // cerr << "select " << pa << " (" << id << endl;
            assert(pa < 2 * n);
        }
        // select from vb
        {
            int a, b, id;
            tie(a, b, id) = vb[pb];
            while (vis[id]) {
                pb++;
                tie(a, b, id) = vb[pb];
            }
            vis[id] = true;
            ansb += a;
            // cerr << "select " << pb << " (" << id << endl;
            assert(pb < 2 * n);
        }
    }
    cout << ansa << " " << ansb << endl;
}