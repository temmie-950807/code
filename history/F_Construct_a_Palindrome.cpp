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
const int MAX_N = 1000+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m;
int a, b;
char c;
vector<vector<vector<int>>> G(MAX_N, vector<vector<int>>(26));
queue<tuple<int, int, int>> qq; // status, step
vector<bitset<MAX_N>> arr(MAX_N), reach(MAX_N), vis(MAX_N);

void solve1(){
    
    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        G[a][c-'a'].push_back(b);
        G[b][c-'a'].push_back(a);
        arr[a][c-'a']=1;
        arr[b][c-'a']=1;
        reach[a][b]=1;
        reach[b][a]=1;
    }

    // prcess
    qq.push({1, n, 0});
    vis[1][n]=1;
    vis[n][1]=1;

    int ans=INF;
    while (qq.size()){
        int node_A=get<0>(qq.front());
        int node_B=get<1>(qq.front());
        int step  =get<2>(qq.front());
        qq.pop();

        // odd len palindrome
        if (node_A==node_B){
            ans=min(ans, step*2);
        }

        // even len palindrome
        if (reach[node_A][node_B]==1){
            ans=min(ans, step*2+1);
        }

        // find next road
        for (int i=0 ; i<26 ; i++){
            if (arr[node_A][i]==1 && arr[node_B][i]==1){
                for (auto x : G[node_A][i]){
                    for (auto y : G[node_B][i]){
                        if (vis[x][y]==0){
                            vis[x][y]=1;
                            vis[y][x]=1;
                            qq.push({x, y, step+1});
                        }
                    }
                }
            }
        }
    }
    
    // output
    cout << (ans==INF ? -1 : ans) << "\n";
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