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
const int MAX_N = 400+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, a, b;
vector<vector<pair<int, int>>> G(MAX_N); // from -> <to, id>
vector<pair<int, int>> v(1); // <from, to>

queue<pair<int, int>> qq; // <from, len>
bitset<MAX_N> vis;

int ans;
vector<pair<int, int>> parent(MAX_N); // <parent, id>
bitset<MAX_N*MAX_N> on_path;

int bfs(int id){

    // init
    while (qq.size()) qq.pop();
    vis=0;
    
    vis[1]=1;
    qq.push({1, 0});
    while (qq.size()){
        int now=qq.front().first;
        int len=qq.front().second;
        qq.pop();

        if (now==n){
            return len;
        }

        for (auto x : G[now]){
            if (now==v[id].first && x.first==v[id].second){
                continue;
            }
            if (vis[x.first]==0){
                vis[x.first]=1;
                parent[x.first].first=now;
                parent[x.first].second=x.second;
                qq.push({x.first, len+1});
            }
        }
    }

    return -1;
}

void solve1(){

    // input
    cin >> n >> m;
    for (int i=1 ; i<=m ; i++){
        cin >> a >> b;
        G[a].push_back({b, i});
        v.push_back({a, b});
    }

    // process
    ans=bfs(0);

    // get path
    int now=n;
    while (now!=0){
        on_path[parent[now].second]=1;
        now=parent[now].first;
    }

    // output
    for (int i=1 ; i<=m ; i++){
        if (on_path[i]==0){
            cout << ans << "\n";
        }else{
            cout << bfs(i) << "\n";
        }
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