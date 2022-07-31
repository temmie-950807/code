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
int n, q, tmp, a, b, c, d;
vector<int> v(MAX_SIZE), seg_tree(MAX_SIZE*4), tag(MAX_SIZE*4);

// 左子樹: [l, mid];
// 右子樹: [mid+1, r];

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

void push_tag(int index, int l, int r){
    if (tag[index]!=0){
        int mid = (l+r)/2;

        // 更新左子樹
        seg_tree[index*2] += (mid-l+1) * tag[index];
        // 更新右子樹
        seg_tree[index*2+1] += (r-mid) * tag[index];

        // 下推標記
        tag[index*2] = tag[index];
        tag[index*2+1] = tag[index];
        // 重置標記
        tag[index] = 0;
    }
    return;
}

void modify(int L, int R, int val, int index, int l, int r){
    if (l!=r){
        push_tag(index, l, r);
    }

    if (L<=l && r<=R){ // 完全在區間裡面
        seg_tree[index] += (r-l+1)*val;
        tag[index] += val;
        return;
    }

    int mid = (l+r)/2;

    if (R<=mid) modify(L, R, val, index*2, l, mid);
    else if (L>mid) modify(L, R, val, index*2+1, mid+1, r);
    else{
        modify(L, R, val, index*2, l, mid);
        modify(L, R, val, index*2+1, mid+1, r);
    }

    seg_tree[index] = seg_tree[index*2]+seg_tree[index*2+1];
}

int query(int L, int R, int index, int l, int r){
    if (l!=r){
        push_tag(index, l, r);
    }

    int mid = (l+r)/2;

    if (L<=l && r<=R) return seg_tree[index];
    else if (R<=mid) return query(L, R, index*2, l, mid);
    else if (L>mid) return query(L, R, index*2+1, mid+1, r);
    else return query(L, R, index*2, l, mid)+query(L, R, index*2+1, mid+1, r);
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
        cin >> a;
        if (a==1){
            cin >> b >> c >> d;
            modify(b, c, d, 1, 1, n);
        }
        if (a==2){
            cin >> b;
            cout << query(b, b, 1, 1, n) << "\n";
        }
    }
    return 0;
}