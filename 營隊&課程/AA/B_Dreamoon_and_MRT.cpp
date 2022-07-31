#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, tmp, ans=INF;
vector<int> v;
vector<bool> a(6e6, 0);

void f(int now, int total, int p){
    if (total>ans) return;
    else if (p==n){
        ans = min(ans, total);
    }else{
        bool check_1=(a[now+v[p]]==0), check_2=(a[now-v[p]]==0);

        a[now+v[p]] = 1;
        f(now+v[p], total+check_1, p+1);
        if (check_1) a[now+v[p]] = 0;

        
        a[now-v[p]] = 1;
        f(now-v[p], total+check_2, p+1);
        if (check_2) a[now-v[p]] = 0;
    }
    return;
}

signed main(void){
    fastio;
    
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // recursive
    a[3e6] = 1;
    f(3e6, 1, 0);

    // output
    cout << ans << "\n";

    return 0;
}