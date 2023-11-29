#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=2e5+5;
const int INF=2e18;

int n, tmp;
int a, b, c;
vector<int> v(1);
vector<vector<pair<int, int>>> G(MAX_N);

void dfs(vector<vector<int>> &dis, int start, int now, int pre, int dd){
    dis[start][now]=dd;

    for (auto x : G[now]){
        if (x.first!=pre){
            dfs(dis, start, x.first, now, dd+x.second);
        }
    }
}

struct disjoint_set{

    vector<int> arr;

    void init(int n){
        n+=5;
        arr.resize(n);
        for (int i=0 ; i<n ; i++){
            arr[i]=i;
        }
    }

    int find(int a){
        if (arr[a]==a) return a;
        else return arr[a]=find(arr[a]);
    }

    void unite(int a, int b){
        a=find(a);
        b=find(b);
        arr[a]=b;
    }
} dsu;

void solve1(){

    // init
    vector<vector<int>> dis(1005, vector<int>(1005));
    vector<tuple<int, int, int>> pp;

    // process
    for (int i=1 ; i<=n ; i++){
        dfs(dis, i, i, 0, 0);
        for (int j=1 ; j<=n ; j++){
            pp.push_back({dis[i][j]+v[i]+v[j], i, j});
        }
    }

    sort(pp.begin(), pp.end());
    dsu.init(n);
    int total=0;
    for (auto &[val, u, v] : pp){
        if (dsu.find(u)!=dsu.find(v)){
            total+=val;
            dsu.unite(u, v);
        }
    }

    // output
    cout << total << "\n";
}

void solve2(){

    int total=0;

    int mi=INF, idx=-1;
    for (int i=2 ; i<=n ; i++){
        total+=v[1]+v[i]+G[i][0].second;

        if (v[i]+G[i][0].second<mi){
            mi=v[i]+G[i][0].second;
            idx=i;
        }
    }

    if (mi<v[1]){
        for (int i=2 ; i<=n ; i++){
            if (i==idx) continue;
            total-=v[1];
            total+=mi;
        }
        cout << total << "\n";
    }else{
        cout << total << "\n";
    }
}

signed main(void){
    int t=1;
    while (t--){

        cin >> n;
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        for (int i=0 ; i<n-1 ; i++){
            cin >> a >> b >> c;
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }

        if (n<=1000){
            solve1();
        }else{
            solve2();
        }
    }
    return 0;
}