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
int k, check=1, pos, l;
string s;
gp_hash_table<int, int> h;

signed main(void){
    fastio;
    
    cin >> s;
    for (int i=0 ; i<6 ; i++){
        h[i]=0;
    }
    for (int i=0 ; i<s.size() ; i++){
        h[s[i]-'A']++;
    }

    int check_end=0;
    while (check){
        // init
        check=0;

        // 對角方向抵銷
        for (k=0 ; k<6 ; k++){
            pos=(k+3)%6;
            l=min(h[k], h[pos]);
            if (l>0){
                check=1;
            }
            h[k]-=l;
            h[pos]-=l;
        }
        for (k=0 ; k<6 ; k++){
            // +120抵銷
            pos=(k+2)%6;
            l=min(h[k], h[pos]);
            if (l>0){
                check=1;
            }
            h[k]-=l;
            h[pos]-=l;
            h[(k+1)%6]+=l;

            // -120抵銷
            pos=(k+4)%6;
            l=min(h[k], h[pos]);
            if (l>0){
                check=1;
            }
            h[k]-=l;
            h[pos]-=l;
            h[(k+5)%6]+=l;
        }

    }

    int ans=0;
    for (auto x : h){
        ans += x.second;
    }
    cout << ans << "\n";
    return 0;
}