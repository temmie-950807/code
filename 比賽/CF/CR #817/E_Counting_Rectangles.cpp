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
int t, n, q, h, w, ah, aw, bh, bw;
int arr[1005][1005];
vector<pair<int, int>> v;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        memset(arr, 0, sizeof(arr));

        // input
        cin >> n >> q;
        for (int i=0 ; i<n ; i++){
            cin >> h >> w;
            arr[h][w]+=h*w;
        }

        // pre-process
        for (int i=1 ; i<=1000 ; i++){
            for (int j=1 ; j<=1000 ; j++){
                arr[i][j]=arr[i][j] + arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }
        }

        for (int i=0 ; i<q ; i++){
            cin >> ah >> aw >> bh >> bw;
            if (ah>bh || aw>bw) cout << "0\n";
            else{
                cout << arr[bh-1][bw-1]-arr[bh-1][aw]-arr[ah][bw-1]+arr[ah][aw] << "\n";
            }
        }
        
        
    }
    return 0;
}