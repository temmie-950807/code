#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, m;
int mx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int my[8]={-2, -1, 1, 2, -2, -1, 1, 2};

// function
bool out(int x, int y){
    return (x<=0 || x>n || y<=0 || y>m);
}

void solve(){
    cin >> n >> m;
    
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            // get each cell
            int cnt=0;
            for (int k=0 ; k<8 ; k++){
                cnt+=out(i+mx[k], j+my[k]);
            }

            if (cnt==8){
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << "1 1" << endl;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}