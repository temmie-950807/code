#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 5e2+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int t, n, m;
string s;
int arr[MAX_SIZE][MAX_SIZE];

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        memset(arr, -1, sizeof(arr));

        // input
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++){
            cin >> s;
            for (int j=1 ; j<=m ; j++){
                arr[i][j]=s[j-1]-'0';
            }
        }
        
        int check=0, cnt=0;
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                if (arr[i][j]==0){
                    if (arr[i-1][j]==0) check=2;
                    else if (arr[i][j-1]==0) check=2;
                    else if (arr[i+1][j]==0) check=2;
                    else if (arr[i][j+1]==0) check=2;
                    else if (arr[i+1][j+1]==0) check=2;
                    else if (arr[i-1][j+1]==0) check=2;
                    else if (arr[i-1][j-1]==0) check=2;
                    else if (arr[i+1][j-1]==0) check=2;
                    else check=max(check, 1LL);

                }else if (arr[i][j]==1){
                    cnt++;
                }
            }
        }


        if (check==2){
            cout << cnt << "\n";
        }else if (check==1){
            cout << max(0LL, cnt-1) << "\n";
        }else{
            cout << max(0LL, cnt-2) << "\n";
        }
        
    }
    return 0;
}