#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=5e5;

int n;
vector<vector<int>> G(MAX_N);

void solve1(){
    if (n%2==0){
        cout << "Little P\n";
    }else{
        cout << "Little Y\n";
    }
}

int dfs(int now, int pre){ // 回傳深度
    int ret=0;

    for (auto x : G[now]){
        if (x!=pre){
            ret=max(ret, dfs(x, now));
        }
    }

    return ret+1;
}

void solve2(){
    int a=dfs(1, n);
    int b=dfs(n, 1);

    if (a<=b){
        cout << "Little P\n";
    }else{
        cout << "Little Y\n";
    }
}

signed main(void){

    fastio;

    int t=1;
    while (t--){

        bool flag=1;

        // input
        cin >> n;
        for (int i=1 ; i<n ; i++){
            int a, b;
            cin >> a >> b;
            if (b!=a+1) flag=0;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        if (flag){
            solve1();
        }else{
            solve2();
        }
    }

    return 0;
}

/*
3
3 5
1 4
1 9
*/

/*
7
3 1
1 6
3 1
3 1
1 2
2 1
1 1
*/

/*
8
3 1000000
1 1000000
2 999999
3 1000000
1 1000000
2 999999
3 1000000
1 1000000
*/