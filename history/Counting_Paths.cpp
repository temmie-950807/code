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
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, a, b;
vector<vector<int>> G(MAX_N);
vector<vector<int>> p(25, vector<int>(MAX_N));
vector<int> dep(MAX_N), dp(MAX_N);

void dfs(int now, int pre){
    dep[now]=(now==0 ? 0 : dep[pre]+1);
    p[0][now]=(now==0 ? -1 : pre);

    for (auto x : G[now]){
        if (x!=pre){
            dfs(x, now);
        }
    }
}

void build(){
    int h=__lg(n)+1;
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<n ; j++){
            if (p[i][j]!=-1) p[i+1][j]=p[i][p[i][j]];
            else p[i+1][j]=-1;
        }
    }
}

int jump(int pos, int dis){
    for (int i=0 ; i<p.size() ; i++){
        if ((dis>>i)&1){
            pos=p[i][pos];
        }
    }
    return pos;
}

int lca(int a, int b){
    if (dep[a]>dep[b]) swap(a, b);
    b=jump(b, dep[b]-dep[a]);
    if (a==b) return a;

    for (int i=p.size()-1 ; i>=0 ; i--){
        int c=p[i][a];
        int d=p[i][b];
        if (c!=d){
            a=c;
            b=d;
        }
    }

    return p[0][a];
}

void dfs2(int now, int pre){
    for (auto x : G[now]){
        if (x!=pre){
            dfs2(x, now);
            dp[now]+=dp[x]; // 樹上差分還原
        }
    }
}

void solve1(){
    
    // input
    cin >> n >> m;
    for (int i=0 ; i<n-1 ; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // build
    dfs(0, 0);
    build();

    // process
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        a--;
        b--;

        dp[a]++;
        dp[b]++;
        dp[lca(a, b)]--;
        if (p[0][lca(a, b)]==-1) continue;
        else dp[p[0][lca(a, b)]]--;
    }
    dfs2(0, 0);

    // output
    for (int i=0 ; i<n ; i++){
        cout << dp[i] << " ";
    }   cout << "\n";

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