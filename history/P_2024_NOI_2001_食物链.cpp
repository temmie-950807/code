#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define F first
#define S second
using namespace std;

// declare
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q;
int op, x, y;
const int v[3]={0, 1, 2}; // 0 吃 1，1 吃 2...

struct disjoint_set{
    int n;
    vector<int> arr, dis;

    disjoint_set(int _n){
        n=_n+5;
        arr.resize(n);
        dis.resize(n);
        for (int i=0 ; i<n ; i++){
            arr[i]=i;
        }
    }

    int find(int a){
        if (arr[a]==a){
            return a;
        }else{
            int r=find(arr[a]);
            dis[a]=(dis[a]+dis[arr[a]])%3;
            return arr[a]=r;
        }
    }

    bool unite(int a, int b, int op){
        int ra=find(a);
        int rb=find(b);

        if (ra!=rb){
            if (op==1){
                arr[ra]=rb;
                dis[ra]=((dis[b]-1-dis[a])%3+3)%3;
                // dis[a] + delta + 1 = dis[b]
                // delta = dis[b] - 1 - dis[a]
            }else if (op==2){
                arr[ra]=rb;
                dis[ra]=((dis[b]-dis[a])%3+3)%3;
                // dis[a] + delta = dis[b]
                // delta = dis[b] - dis[a]
            }
            return 1;
        }else{
            if (op==1){
                return ((dis[a]+1)%3==dis[b]);
            }else if (op==2){
                return dis[a]==dis[b];
            }
        }
        return 1;
    }
};

void solve1(){

    // input
    cin >> n >> q;

    // queries
    disjoint_set dsu(n);
    int ans=0;
    for (int i=0 ; i<q ; i++){
        cin >> op >> x >> y;
        op=3-op;
        if (x>n || y>n || (op==1 && x==y)){
            ans++;
        }else{
            ans+=!(dsu.unite(x, y, op));
        }
    }
    
    // output
    cout << ans << "\n";

    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}