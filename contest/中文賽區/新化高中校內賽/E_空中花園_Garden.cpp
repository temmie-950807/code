#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
struct Data{
    int xa, ya, xb, yb, t, idx;

    bool operator < (Data A){
        return t<A.t;
    }
} D;

int n, m, tmp;
int q;
int arr[505][505], pre[505][505];

vector<Data> qq;
int ans[MAX_SIZE];

// function
int quick_pow(int b, int p){
    int ret=1;

    while (p){
        if (p&1){
            ret=ret*b%10;
        }

        p>>=1;
        b=b*b%10;
    }
    
    return ret;
}

signed main(void){
    fastio;
    
    // input
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            cin >> tmp;
            arr[i][j]=tmp%10;
        }
    }

    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> D.xa >> D.ya >> D.xb >> D.yb >> D.t;
        D.idx=i;
        qq.push_back(D);
    }
    sort(qq.begin(), qq.end());

    // input
    int ptr=0;
    for (int kk=0 ; kk<=20 ; kk++){
        // init
        memset(pre, 0, sizeof(pre));

        // rebuild prefix sum
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                arr[i][j]=quick_pow(arr[i][j], (1<<kk));
                pre[i][j]=(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1] + arr[i][j])%10;
                while (pre[i][j]<0){
                    pre[i][j]=(pre[i][j]+10)%10;
                }
            }
        }

        // output
        while (ptr<q && qq[ptr].t==kk+1){
            ans[qq[ptr].idx]=(pre[qq[ptr].xb][qq[ptr].yb]-pre[qq[ptr].xa-1][qq[ptr].yb]-pre[qq[ptr].xb][qq[ptr].ya-1]+pre[qq[ptr].xa-1][qq[ptr].ya-1])%10;
            
            while (ans[qq[ptr].idx]<0){
                ans[qq[ptr].idx]=(ans[qq[ptr].idx]+10)%10;
            }
            ptr++;
        }
    }

    while (ptr<q){
        ans[qq[ptr].idx]=(pre[qq[ptr].xb][qq[ptr].yb]-pre[qq[ptr].xa-1][qq[ptr].yb]-pre[qq[ptr].xb][qq[ptr].ya-1]+pre[qq[ptr].xa-1][qq[ptr].ya-1])%10;
        
        while (ans[qq[ptr].idx]<0){
            ans[qq[ptr].idx]=(ans[qq[ptr].idx]+10)%10;
        }
        ptr++;
    }

    // output
    for (int i=0 ; i<q ; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}