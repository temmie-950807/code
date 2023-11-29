#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=1e3+5;

int n, m, tmp;
vector<int> v(1);
vector<vector<int>> G(MAX_N, vector<int>(MAX_N, -1));
priority_queue<tuple<int, int, int>> pq;
int total=0;

struct dsu{

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

void solve2(){
    sort(v.begin()+1, v.end());

    int total=0;
    for (int i=2 ; i<=n ; i++){
        total+=v[i]+v[1];
    }

    cout << total << "\n";
}

void solve3(){
    for (int i=0 ; i<m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }

    // process
    dsu.init(n);
    while (pq.size()){
        auto [a, b, c]=pq.top();
        pq.pop();

        if (dsu.find(b)!=dsu.find(c)){
            dsu.unite(b, c);
            total-=a;
        }
    }

    for (int i=1 ; i<=n ; i++){
        if (dsu.find(i)!=dsu.find())
    }

    // output
    cout << total << "\n";
}

void solve1(){
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    if (m==0){
        solve2();
        return;
    }else if (n>1000 || m>1000){
        solve3();
        return;
    }

    for (int i=0 ; i<m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b]=c;
        G[b][a]=c;
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            if (i==j) continue;
            if (G[i][j]==-1){
                pq.push({-v[i]-v[j], i, j});
            }else{
                pq.push({-G[i][j], i, j});
            }
        }
    }

    // process
    dsu.init(n);
    while (pq.size()){
        auto [a, b, c]=pq.top();
        pq.pop();

        if (dsu.find(b)!=dsu.find(c)){
            dsu.unite(b, c);
            total-=a;
        }
    }

    // output
    cout << total << "\n";
}

signed main(void){

    fastio;

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}