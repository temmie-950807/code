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

int n, m, s, t;
int a, b, c;
typedef pair<int, int> pii;
vector<vector<pii>> G(MAX_N); // from -> <weight, to>
priority_queue<pii, vector<pii>, greater<pii>> pq; // {weight, from}
vector<int> dis(MAX_N, 1e15); // INF 不可以開太大，不然會 overflow
vector<int> from(MAX_N); // 紀錄是由誰轉移

void solve1(){
    
    // input
    cin >> n >> m >> s >> t;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b >> c;
        G[a].push_back({c, b});
    }

    // process
    pq.push({0, s});
    dis[s]=0;
    while (pq.size()){
        auto [now_weight, now_node]=pq.top();
        pq.pop();

        if (now_weight!=dis[now_node]) continue;

        for (auto [nxt_weight, nxt_node] : G[now_node]){
            if (dis[now_node]+nxt_weight<dis[nxt_node]){
                dis[nxt_node]=dis[now_node]+nxt_weight;
                from[nxt_node]=now_node;
                pq.push({dis[now_node]+nxt_weight, nxt_node});
            }
        }
    }

    if (dis[t]==1e15){
        cout << -1 << "\n";
        return;
    }

    // 回朔解
    cout << dis[t] << " ";
    vector<int> ans(1, t);
    do{
        t=from[t];
        ans.push_back(t);
    } while (t!=s);
    reverse(ans.begin(), ans.end());

    // output
    cout << ans.size()-1 << "\n";
    for (int i=0 ; i<ans.size()-1 ; i++){
        cout << ans[i] << " " << ans[i+1] << "\n";
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