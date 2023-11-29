#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// debugger
// ===================================
bool debug_mode=true;
#define cerr if(debug_mode) cerr
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
template<typename T>void debug(const T &v,int h,int w,string sv=" "){for(int i=0;i<h;i++){cerr<<v[i][0];for(int j=1;j<w;j++)cerr<<sv<<v[i][j];cerr<<endl;}};
template<typename T>void debug(const T &v,int n,string sv=" "){if(n!=0)cerr<<v[0];for(int i=1;i<n;i++)cerr<<sv<<v[i];cerr<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop_front();}cerr<<endl;}
template<typename T>void debug(priority_queue<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(priority_queue<T, vector<int>, greater<int>> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cerr<<"["<<z.first<<"]="<<z.second<<", ";cerr<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cerr<<z<<" ";cerr<<endl;}
// ===================================

// declare
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, tmp;
int a, b, c;
// vector<vector<pair<int, int>>> G(MAX_N);
vector<tuple<int, int, int>> G;
// 節點 n+1 -> airport
// 節點 n+2 -> harbor

struct Disjoint_Set{
    vector<int> arr, sz;

    void init(int n){ // 使用前，要傳入陣列大小初始化
        arr.resize(n+10);
        sz.resize(n+10);
        for (int i=0 ; i<n+10 ; i++){
            arr[i]=i;
            sz[i]=1;
        }
    }

    int find(int a){ // 回傳 a 節點的 leader
        if (arr[a]==a) return a;
        else return arr[a]=find(arr[a]); // 路徑壓縮優化
    }

    void unite(int a, int b){ // 將兩個節點合併
        a=find(a);
        b=find(b);

        if (a!=b){
            if (sz[a]<sz[b]) swap(a, b); // 啟發式合併優化
            arr[b]=a;
            sz[a]+=sz[b];
        }
    }
};

int kruskal(int ex1=-1, int ex2=-1){
    int ans=0, p=n+(ex1==-1)+(ex2==-1);
    Disjoint_Set dsu;
    dsu.init(n);

    for (auto &[a, b, c] : G){
        if (b==ex1 || b==ex2 || c==ex1 || c==ex2) continue;
        if (dsu.find(b)==dsu.find(c)) continue;
        ans+=a;
        dsu.unite(b, c);
        p--;
    }

    if (p==1) return ans;
    else return INF;
}

void solve1(){

    // input
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        G.push_back({tmp, i, n+1});
    }
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        G.push_back({tmp, i, n+2});
    }
    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        G.push_back({c, a, b});
    }

    // process
    sort(G.begin(), G.end());
    int mi=INF;
    mi=min(mi, kruskal(-1, -1));
    mi=min(mi, kruskal(n+1, -1));
    mi=min(mi, kruskal(-1, n+2));
    mi=min(mi, kruskal(n+1, n+2));

    // output
    cout << mi << "\n";
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