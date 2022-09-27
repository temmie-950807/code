#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 100000+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
struct node{
    int seg, pref, suf, sum;
};
int n, m, tmp;
int a, b;
vector<int> v;
vector<node> seg_tree(4*MAX_SIZE);

// function
void build(vector<int> *a, int now, int ll, int rr){
    if (rr-ll==1){
        if ((*a)[ll]>0){ // 只有一點, 大於0則必定是最大值
            seg_tree[now]={(*a)[ll], (*a)[ll], (*a)[ll], (*a)[ll]};
        }else{ // 此時不選就會是最大值
            seg_tree[now]={0, 0, 0, (*a)[ll]};
        }
    }else{
        int mid=(ll+rr)/2;
        build(a, 2*now+1, ll, mid);
        build(a, 2*now+2, mid, rr);

        node A=seg_tree[2*now+1];
        node B=seg_tree[2*now+2];
        seg_tree[now]={
            max({A.seg, B.seg, A.suf+B.pref}),
            max(A.pref, A.sum+B.pref),
            max(B.suf, B.sum+A.suf),
            A.sum+B.sum,
        };
    }
    return;
}
void update(int idx, int val, int now, int ll, int rr){
    if (rr-ll==1){
        if (val>0){ // 只有一點, 大於0則必定是最大值
            seg_tree[now]={val, val, val, val};
        }else{ // 此時不選就會是最大值
            seg_tree[now]={0, 0, 0, val};
        }
    }else{
        int mid=(ll+rr)/2;
        if (idx<mid) update(idx, val, 2*now+1, ll, mid);
        else update(idx, val, 2*now+2, mid, rr);

        node A=seg_tree[2*now+1];
        node B=seg_tree[2*now+2];
        seg_tree[now]={
            max({A.seg, B.seg, A.suf+B.pref}),
            max(A.pref, A.sum+B.pref),
            max(B.suf, B.sum+A.suf),
            A.sum+B.sum,
        };
    }
    return;
}

signed main(void){
    fastio;
    
    // input
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    build(&v, 0, 0, n);

    cout << seg_tree[0].seg << "\n";

    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        update(a, b, 0, 0, n);

        cout << seg_tree[0].seg << "\n";
    }
    return 0;
}