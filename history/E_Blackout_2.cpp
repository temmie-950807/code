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
const int MAX_N = 7e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, e;
int q;
int a, b;
vector<int> v;
vector<pair<int, int>> edges(1);
bitset<MAX_N> vis;

int ans=0;
vector<int> sz(MAX_N), dsu(MAX_N), city_num(MAX_N), plant_num(MAX_N);

// function
int f(int a){
    return plant_num[a] ? city_num[a] : 0;
}

int find(int a){
    return dsu[a]==a ? a : dsu[a]=find(dsu[a]);
}

void unite(int a, int b){
    a=find(a);
    b=find(b);

    if (a!=b){
        if (sz[a]>sz[b]) swap(a, b);

        ans-=f(a);
        ans-=f(b);

        dsu[a]=b;
        sz[b]+=sz[a];
        city_num[b]+=city_num[a];
        plant_num[b]+=plant_num[a];

        ans+=f(b);
    }
}

void solve1(){

    // input
    cin >> n >> m >> e;
    for (int i=0 ; i<e ; i++){
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a;
        v.push_back(a);
        vis[a]=1;
    }

    // init
    for (int i=1 ; i<=n+m ; i++){
        sz[i]=1;
        dsu[i]=i;
        if (i<=n) city_num[i]=1;
        else plant_num[i]=1;
    }
    for (int i=1 ; i<=e ; i++){
        if (vis[i]==0){
            unite(edges[i].first, edges[i].second);
            cerr << edges[i].first << " " << edges[i].second << "\n";
        }
    }

    dbg(ans);

    // process
    vector<int> op;
    for (int i=q-1 ; i>=0 ; i--){
        op.push_back(ans);
        unite(edges[v[i]].first, edges[v[i]].second);
    }

    for (int i=q-1 ; i>=0 ; i--){
        cout << op[i] << "\n";
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