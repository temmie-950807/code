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
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, a, b;
int x, y;
vector<vector<int>> G;

vector<int> sta, vis;
vector<int> dis_A, dis_B;
bitset<MAX_N> in_cycle;

void resz(int n){
    G.resize(n+5);
    vis.resize(n+5);
    dis_A.resize(n+5);
    dis_B.resize(n+5);
}

bool dfs(int now, int pre){
    vis[now]=1;
    sta.push_back(now);

    for (auto x : G[now]){
        if (x==pre) continue;
        else if (vis[x]==0){
            if (dfs(x, now)==1){
                return 1;
            }
        }else if (vis[x]==1){
            in_cycle[x]=1;
            do{
                in_cycle[sta.back()]=1;
                sta.pop_back();
            } while (sta.back()!=x);
            return 1;
        }
    }

    vis[now]=2;
    sta.pop_back();
    return 0;
}

void bfs(int start, vector<int> &rec){
    queue<int> qq;
    fill(vis.begin(), vis.end(), 0);

    qq.push(start);
    rec[start]=0;
    vis[start]=1;
    while (qq.size()){
        int now=qq.front();
        qq.pop();

        for (auto x : G[now]){
            if (vis[x]==0){
                qq.push(x);
                rec[x]=rec[now]+1;
                vis[x]=1;
            }
        }
    }
    
}

void solve1(){

    // init
    G.clear();
    sta.clear();
    vis.clear();
    in_cycle=0;

    // input
    cin >> n >> a >> b;
    resz(n);
    for (int i=0 ; i<n ; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // process - special case
    if (a==b){
        cout << "NO\n";
        return;
    }

    // process - find cycle
    fill(vis.begin(), vis.end(), 0);
    dfs(1, 0);

    // process - find shortest path
    bfs(a, dis_A);
    bfs(b, dis_B);

    // process - find answer
    if (in_cycle[b]){
        cout << "YES\n";
        return;
    }else{
        for (int i=1 ; i<=n ; i++){
            if (in_cycle[i]){
                if (dis_B[i]<dis_A[i]){
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
        return;
    }

    // preview
    cerr << "in_cycle: ";
    for (int i=1 ; i<=n ; i++){
        if (in_cycle[i]){
            cerr << i << " ";
        }else{
            cerr << "_ ";
        }
    }
    cerr << "\n";
    cerr << "dis_A:    ";
    for (int i=1 ; i<=n ; i++){
        cerr << dis_A[i] << " ";
    }
    cerr << "\n";
    cerr << "dis_B:    ";
    for (int i=1 ; i<=n ; i++){
        cerr << dis_B[i] << " ";
    }
    cerr << "\n";
    cerr << "\n";

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