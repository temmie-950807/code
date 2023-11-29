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
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, h, tmp;
int q, a, b;
vector<int> v, dep;
vector<vector<int>> G, pre;

void init(){
    v.clear();
    dep.clear();
    G.clear();
    pre.clear();

    G.resize(n+5);
    dep.resize(n+5);
    pre.resize(30, vector<int>(n+5)); // 走 2^i 步會走到的點
    h=__lg(n);
}

void dfs(int now, int parent){
    pre[0][now]=parent;
    dep[now]=dep[parent]+1;

    for (auto x : G[now]){
        if (x!=parent){
            dfs(x, now);
        }
    }
}

int jump(int now, int step){
    for (int i=0 ; i<=h ; i++){
        if ((step>>i)&1){
            now=pre[i][now];
        }
    }

    return now;
}

int lca(int a, int b){
    if (dep[a]<dep[b]) swap(a, b);
    a=jump(a, dep[a]-dep[b]);
    if (a==b) return a;

    for (int i=h ; i>=0 ; i--){
        if (jump(a, (1<<i))!=jump(b, (1<<i))){
            a=jump(a, (1<<i));
            b=jump(b, (1<<i));
        }
    }
    a=jump(a, 1);
    return a;
}

void solve1(){

    // init
    cin >> n;
    init();

    // input
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // pre-process
    dfs(1, 0); // get pre
    for (int i=1 ; i<=h ; i++){
        for (int j=1 ; j<=n ; j++){
            pre[i][j]=pre[i-1][pre[i-1][j]];
        }
    }

    // preview
    cerr << "dep: \n";
    for (int i=1 ; i<=n ; i++){
        cerr << dep[i] << " ";
    }
    cerr << "\n";

    cerr << "pre: \n";
    for (int i=0 ; i<=h ; i++){
        for (int j=1 ; j<=n ; j++){
            cerr << pre[i][j] << " ";
        }
        cerr << "\n";
    }

    // queries
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        cerr << lca(a, b) << "\n";
    }
    
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }
    return 0;
}