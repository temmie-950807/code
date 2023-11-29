#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define F first
#define S second
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
const int MAX_N = 19;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m;
int a, b;
vector<vector<int>> G(MAX_N);

/*
時間可以到 O(2^n * n^2)
空間可以到 O(2^n * n)
dp[state] = 只看 state 的點，
*/

bool get_bit(int val, int pos){
    return (val>>pos)&1;
}

void solve1(){

    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // process
    int ans=0;
    for (int lim=n ; lim>0 ; lim--){
        vector<vector<int>> dp(lim, vector<int>(1<<lim));
        // dp[pos][state] = state 的點上，最後走到 pos 的點
        dp[lim-1][(1<<(lim-1))]=1;

        for (int now=(1<<(lim-1)) ; now<(1<<lim) ; now++){
            string s=bitset<4>(now).to_string();
            reverse(s.begin(), s.end());
            for (int pos=0 ; pos<lim ; pos++){
                // dbg(now, pos);

                if (get_bit(now, pos)){
                    for (auto nxt_pos : G[pos]){
                        if (nxt_pos>=lim) continue;
                        if (get_bit(now, nxt_pos)==0){
                            dp[nxt_pos][now|(1<<nxt_pos)]+=dp[pos][now];
                        }
                    }
                }
            }
            if (__builtin_popcount(now)>=3){
                int add=0;
                for (auto x : G[lim-1]){
                    if (x>=lim) continue;
                    ans+=dp[x][now];
                    add+=dp[x][now];
                }
            }
        }
    }

    // output
    cout << ans/2 << "\n";
    
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