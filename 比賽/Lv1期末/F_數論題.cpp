#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 5e6+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
bool check;
int a, b, m, q, tmp;
vector<int> v;
queue<pair<int, int>> que;
bitset<MAX_SIZE> vis;

signed main(void){
    fastio;
    
    cin >> a >> b >> m >> q;
    for (int i=0 ; i<q ; i++){
        cin >> tmp;

        if (tmp==1){
            cout << "0\n";
        }else{
            // init
            while (!que.empty()) que.pop();
            que.push({tmp, 0});
            vis=0;
            check=1;

            while (que.size()){
                pair<int, int> now=que.front();
                que.pop();

                if (now.first==1){
                    cout << now.second << "\n";
                    check=0;
                    break;
                }else{
                    if (vis[(now.first+a)%m]==0){
                        que.push({(now.first+a)%m, now.second+1});
                        vis[(now.first+a)%m]=1;
                    }
                    if (vis[(now.first*b)%m]==0){
                        que.push({(now.first*b)%m, now.second+1});
                        vis[(now.first*b)%m]=1;
                    }
                }
            }
            
            if (check) cout << "-1\n";
            
        }
    }
    return 0;
}