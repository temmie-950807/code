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
const int MAX_N = 2e3+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

const int mx[4]={1, 0, -1, 0};
const int my[4]={0, 1, 0, -1};
int n, m, w;
vector<vector<int>> v(MAX_N, vector<int>(MAX_N));

bool flag=1;
int pp=INF;

bool in(int x, int y){
    return 1<=x && x<=n && 1<=y && y<=m;
}

int bfs(int x, int y){

    vector<bitset<MAX_N>> vis(MAX_N, 0);
    queue<tuple<int, int, int>> qq; // <val, x, y>
    int ret=INF;

    qq.push({0, x, y});
    vis[x][y]=1;
    if (v[x][y]!=0) ret=min(ret, v[x][y]);
    while (qq.size()){
        auto [val, now_x, now_y]=qq.front();
        qq.pop();

        if (flag && now_x==n && now_y==m){
            pp=val;
        }

        for (int i=0 ; i<4 ; i++){
            int new_x=now_x+mx[i];
            int new_y=now_y+my[i];
            // dbg(new_x, new_y);

            if (in(new_x, new_y)){
                if (vis[new_x][new_y]==1) continue;
                vis[new_x][new_y]=1;

                if (v[new_x][new_y]==-1){
                    continue;
                }else if (v[new_x][new_y]==0){
                    qq.push({val+w, new_x, new_y});
                }else{
                    ret=min(ret, val+v[new_x][new_y]+w);
                    qq.push({val+w, new_x, new_y});
                }
            }
        }
    }

    return ret;
}

void solve1(){

    // input
    cin >> n >> m >> w;
    v.resize(n+5, vector<int>(m+5));
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            cin >> v[i][j];
        }
    }

    // process
    int res1=bfs(1, 1);
    flag=0;
    int res2=bfs(n, m);
    if (min(pp, res1+res2)==INF){
        cout << -1 << "\n";
    }else{
        cout << min(pp, res1+res2) << "\n";
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