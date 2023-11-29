#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=5e5+5;

int n, m;
int a, b;
vector<vector<int>> G(MAX_N);
vector<int> A, B;

void solve1(){

    // input
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // process
    vector<int> vis(MAX_N);
    A.push_back(1);
    vis[1]=1;
    for (auto x : G[1]){
        if (vis[x]==0){
            B.push_back(x);
            vis[x]=2;
        }
    }
    for (auto x : B){
        for (auto y : G[x]){
            if (vis[y]==0){
                vis[y]=1;
            }
        }
    }

    cout << 1 << "\n";
    for (int i=1 ; i<=n ; i++){
        // cout << vis[i];
        cout << 2-vis[i];
    }

}

void solve2(){

    // input
    vector<vector<int>> G(n, vector<int>(n));
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a][b]=1;
    }
    
    int ans1=0;
    string ans2(n, '1');
    for (int i=1 ; i<(1<<n) ; i++){
        vector<int> a, b;
        for (int j=0 ; j<n ; j++){
            if ((i>>j)&1){
                a.push_back(j);
            }else{
                b.push_back(j);
            }
        }

        cerr << i << "\n";
        for (auto x : a){
            cerr << x << " ";
        }   cerr << "\n";
        for (auto x : b){
            cerr << x << " ";
        }   cerr << "\n\n";

        bool flag=1;
        for (auto x : a){
            for (auto y : b){
                if (G[x][y]==0){
                    goto gg;
                }
            }
        }

        gg:;

        if (flag){
            ans1++;

            string tmp=bitset<20>(i).to_string();
            reverse(tmp.begin(), tmp.end());
            tmp=tmp.substr(0, n);
            ans2=max(ans2, tmp);
        }
    }

    // output
    cout << ans1 << "\n" << ans2 << "\n";
    
}

signed main(void){

    // input
    cin >> n >> m;

    if (n<=20){
        solve2();
    }else{
        solve1();
    }

    return 0;
}