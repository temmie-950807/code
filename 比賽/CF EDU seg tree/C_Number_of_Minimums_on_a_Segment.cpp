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
int n, m, tmp;
int a, b, c;
vector<int> v(MAX_SIZE);
vector<pair<int, int>> seg_tree(MAX_SIZE*4);

// function
void build(vector<int> *a, int now, int ll, int rr){
    if (rr-ll==1){
        seg_tree[now]={(*a)[ll], 1};
    }else{
        int mid=ll+(rr-ll)/2;
        build(a, 2*now+1, ll, mid);
        build(a, 2*now+2, mid, rr);
        
        if (seg_tree[2*now+1].first==seg_tree[2*now+2].first){
            seg_tree[now]={seg_tree[2*now+1].first, seg_tree[2*now+1].second+seg_tree[2*now+2].second};
        }else{
            if (seg_tree[2*now+1].first<seg_tree[2*now+2].first){
                seg_tree[now]=seg_tree[2*now+1];
            }else{
                seg_tree[now]=seg_tree[2*now+2];
            }
        }
    }
}

void update(int idx, int val, int now, int ll, int rr){
    if (rr-ll==1){ // 目前是根節點
        seg_tree[now]={val, 1};
    }else{
        int mid=ll+(rr-ll)/2;
        if (idx<mid) update(idx, val, 2*now+1, ll, mid); // 要修改的值在右邊
        else update(idx, val, 2*now+2, mid, rr); // 要修改的值在左邊
        
        if (seg_tree[2*now+1].first==seg_tree[2*now+2].first){
            seg_tree[now]={seg_tree[2*now+1].first, seg_tree[2*now+1].second+seg_tree[2*now+2].second};
        }else{
            if (seg_tree[2*now+1].first<seg_tree[2*now+2].first){
                seg_tree[now]=seg_tree[2*now+1];
            }else{
                seg_tree[now]=seg_tree[2*now+2];
            }
        }
    }
    return;
}

pair<int, int> query(int ql, int qr, int now, int ll, int rr){
    if (rr<=ql || qr<=ll) return {INF, 0}; // 完全不包含
    else if (ql<=ll && rr<=qr) return seg_tree[now]; // 完全包含
    else{ // 部分包含
        int mid=ll+(rr-ll)/2;
        pair<int, int> s1=query(ql, qr, 2*now+1, ll, mid);
        pair<int, int> s2=query(ql, qr, 2*now+2, mid, rr);

        if (s1.first==s2.first){
            return {s1.first, s1.second+s2.second};
        }else{
            if (s1.first<s2.first){
                return s1;
            }else{
                return s2;
            }
        }
    }
}

signed main(void){
    fastio;
    
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v[i]=tmp;
    }
    build(&v, 0, 0, n);

    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        if (a==1){
            update(b, c, 0, 0, n);
        }
        if (a==2){

            pair<int, int> pp=query(b, c, 0, 0, n);
            cout << pp.first << " " << pp.second << "\n";
        }
    }
    return 0;
}