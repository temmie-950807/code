#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=1e5+5;

int n, m, tmp;
vector<pair<int, int>> a;
vector<int> aa;
vector<tuple<int, int, int>> v;
vector<map<int, int>> vis(MAX_N);

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
        return arr[a]==a ? a : arr[a]=find(arr[a]);
    }

    void unite(int a, int b){
        arr[find(a)]=find(b);
    }
} dsu;

void solve1(){

    // input
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        a.push_back({tmp, i});
        aa.push_back(tmp);
    }
    for (int i=0 ; i<m ; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        vis[x][y]=1;
        vis[y][x]=1;
        v.push_back({z, x, y});
    }

    // process
    sort(a.begin(), a.end());
    for (int i=0 ; i<n ; i++){
        for (auto [val, idx] : a){
            if (vis[i][idx]==0 && i!=idx){
                vis[i][idx]=1;
                v.push_back({aa[i]+val, i, idx});
                break;
            }
        }
    }

    // MST
    int total=0;
    sort(v.begin(), v.end());
    dsu.init(n);
    for (auto [z, x, y] : v){
        if (dsu.find(x)!=dsu.find(y)){
            total+=z;
            dsu.unite(x, y);
        }
    }
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