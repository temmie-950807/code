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
int n, q, tmp, a, b, c;
vector<int> v(MAX_SIZE), seg_tree(MAX_SIZE*4);

void build(int index, int l, int r){
    if (l==r){
        seg_tree[index] = v[l];
        return ;
    }

    int mid = (l+r)/2;
    build(index*2, l, mid);     // 左子樹
    build(index*2+1, mid+1, r); // 右子樹
    seg_tree[index] = min(seg_tree[index*2], seg_tree[index*2+1]);
    return;
}

void update(int pos, int val, int index, int l, int r){
    if (l==r){
        seg_tree[index] = val;
        return;
    }

    int mid = (l+r)/2;
    if (pos<=mid) update(pos, val, index*2, l, mid);
    else update(pos, val, index*2+1, mid+1, r);
    seg_tree[index] = min(seg_tree[index*2], seg_tree[index*2+1]);
}

int query(int L, int R, int index, int l, int r){
    if (L<=l && r<=R){
        return seg_tree[index];
    }

    int mid = (l+r)/2;

    if (R<=mid) return query(L, R, index*2, l, mid);
    else if (L>mid) return query(L, R, index*2+1, mid+1, r);
    else return min(query(L, R, index*2, l, mid), query(L, R, index*2+1, mid+1, r));
}

signed main(void){
    fastio;
    
    // input
    cin >> n >> q;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        v[i] = tmp;
    }

    // build
    build(1, 1, n);

    // query
    for (int i=1 ; i<=q ; i++){
        cin >> a >> b >> c;
        if (a==1){
            update(b, c, 1, 1, n);
        }
        if (a==2){
            cout << query(b, c, 1, 1, n) << "\n";
        }
    }
    return 0;
}