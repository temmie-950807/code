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
bool debug_mode=false;
#define cerr if(debug_mode) cerr
#define dbg(x) cerr << #x << " = " << x << endl
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
const int MOD = 998'244'353;
const double EPS = 1e-6;

int n, a, b;
int id=0;
vector<int> ans(MAX_N);
vector<vector<int>> G(MAX_N);
struct Disjoint_Set{
    vector<int> arr, sz, now_id;

    void init(int n){ // 使用前，要傳入陣列大小初始化
        arr.resize(n+10);
        sz.resize(n+10);
        now_id.resize(n+10);
        for (int i=0 ; i<n+10 ; i++){
            arr[i]=i;
            sz[i]=1;
            now_id[i]=i;
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

            // 開一個新點 id，並把 a, b 合併至 id 中
            sz[id]=0;

            G[id].push_back(arr[a]);
            G[id].push_back(arr[b]);
            
            arr[a]=arr[id];
            arr[b]=arr[id];

            sz[id]+=sz[a]+sz[b];
            id++;
        }
    }
} dsu;

// function
int qp(int b, int p, int m){
    int ret=1;
    for ( ; p>0 ; p>>=1){
        if (p&1) ret=ret*b%m;
        b=b*b%m;
    }
    return ret;
}

void dfs(int now, int val){
    if (G[now].empty()){
        ans[now]=val;
        return;
    }

    for (auto x : G[now]){
        dbg(dsu.sz[now]);
        dbg(dsu.sz[x]);
        cerr << "\n";
        dfs(x, (val+dsu.sz[x]*qp(dsu.sz[now], MOD-2, MOD))%MOD);
    }
}

void solve1(){

    // init
    cin >> n;
    dsu.init(MAX_N);
    id=n+1;

    // input
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        dsu.unite(a, b);
    }

    // preview
    // for (int i=0 ; i<2*n ; i++){
    //     cerr << "i: " << i << " | sz: " << dsu.sz[i] << " | ";
    //     debug(G[i]);
    // }

    // process
    id--;
    dfs(id, 0);

    // output
    for (int i=1 ; i<=n ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    
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