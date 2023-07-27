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

int n, m;
int a, b;
vector<vector<pair<int, int>>> G(MAX_N);
vector<int> low(MAX_N), dep(MAX_N); // low[i]=i只經過一條回邊可以到的最淺的祖先的深度, dep[i]=節點i的深度
vector<pair<int, int>> ans;
bitset<MAX_N> vis, vis2;

// function
void dfs1(int now){
    vis[now]=1;

    for (auto x : G[now]){
        if (vis[x.first]==0){
            dfs1(x.first);
        }
    }
}

void dfs2(int now, int pre){
    // cerr << "now: " << now << " pre: " << pre << "\n";
    vis[now]=1;
    low[now]=dep[now]=(now==1 ? 0 : dep[pre]+1);

    for (auto x : G[now]){
            // 父節點不理會
        if (x.first!=pre){
            if (vis2[x.second]==0){
                ans.push_back({now, x.first});
                vis2[x.second]=1;
            }

            if (vis[x.first]==0){
                // 向下遞迴看看有沒有更小的 low 值
                dfs2(x.first, now);
                low[now]=min(low[now], low[x.first]);
            }else{
                // 這是一條回邊，檢查是否有更小的 low 值
                low[now]=min(low[now], dep[x.first]);
            }
        }
    }

    if (now!=1 && low[now]==dep[now]){
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
}

void solve1(){

    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    // check1: 圖是否連通
    vis=0;
    dfs1(1);
    if (vis.count()!=n){
        cout << "IMPOSSIBLE\n";
        return;
    }

    // check2: 是否有橋存在
    vis=0;
    vis2=0;
    dfs2(1, 0);

    // output
    for (auto x : ans){
        cout << x.first << " " << x.second << "\n";
    }

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