#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

// declare
int n, m, a, b;
bool check_end = 0;
vector<int> G[MAX_SIZE], team(MAX_SIZE, 0);

void DFS(int x, int k){
    if (k==1){
        team[x] = 2;
    }else{
        team[x] = 1;
    }

    for (auto i : G[x]){
        if (team[i]==1 && k==2){
            check_end = 1;
        }else if (team[i]==2 && k==1){
            check_end = 1;
        }else if (team[i]==0){
            DFS(i, team[x]);
        }
    }


}

signed main(void){
	fastio;
	
    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // DFS
    for (int i=1 ; i<=n ; i++){
        if (team[i]==0){
            team[i] = 1;
            DFS(i, 2);
        }

        if (check_end==1){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // output
    for (int i=1 ; i<=n ; i++){
        cout << team[i] << " ";
    }   cout << "\n";
    return 0;
}