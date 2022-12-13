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
int t, n, tmp;
string s;

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init

        // input
        cin >> n >> s;
        if (n!=5) cout << "NO\n";
        else{
            int check=0;
            for (int i=0 ; i<5 ; i++){
                if (s[i]=='T'){
                    check++;
                    break;
                }
            }
            for (int i=0 ; i<5 ; i++){
                if (s[i]=='i'){
                    check++;
                    break;
                }
            }
            for (int i=0 ; i<5 ; i++){
                if (s[i]=='m'){
                    check++;
                    break;
                }
            }
            for (int i=0 ; i<5 ; i++){
                if (s[i]=='u'){
                    check++;
                    break;
                }
            }
            for (int i=0 ; i<5 ; i++){
                if (s[i]=='r'){
                    check++;
                    break;
                }
            }

            if (check==5) cout << "YES\n";
            else cout << "NO\n";
        }
        
        
    }
    return 0;
}