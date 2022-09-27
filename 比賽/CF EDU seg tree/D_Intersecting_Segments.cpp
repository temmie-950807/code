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
int n, tmp, ii;
vector<int> v;
vector<int> idx(MAX_SIZE), cnt(MAX_SIZE), BIT(MAX_SIZE), ans(MAX_SIZE);

void update(int x, int val){
    for (int i=x ; i<MAX_SIZE ; i+=(i&-i)) BIT[i]+=val;
    return;
}
int query(int x){
    int ret=0;
    for (int i=x ; i>0 ; i-=(i&-i)) ret+=BIT[i];
    return ret;
}

signed main(void){
    fastio;
    
    cin >> n;
    ii=n;

    for (int i=0 ; i<2*n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i=2*n-1 ; i>=0 ; i--){
        cnt[v[i]]++;

        if (cnt[v[i]]==1){
            idx[v[i]]=i--;
            update(idx[v[i]], 1);
        }else{
            ans[v[i]]=query(idx[v[i]]);
            update(idx[v[i]], -1);
        }
    }

    for (int i=0 ; i<n ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}