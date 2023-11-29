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

int n, k, p, tmp;
vector<int> c;
vector<vector<int>> a(105);
vector<vector<int>> dp(105, vector<int>(10000, INF));

int mypow(int n, int p){
    int ret=1;
    for (int i=0 ; i<p ; i++){
        ret*=n;
    }
    return ret;
}

int getbit(int n, int u, int pos){
    for (int i=0 ; i<pos ; i++){
        n/=u;
    }
    return n%u;
}

void solve1(){

    // input
    cin >> n >> k >> p;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        c.push_back(tmp);
        for (int j=0 ; j<k ; j++){
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    // process
    dp[0][0]=0;

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<mypow(p+1, k) ; j++){
            int to=0;
            // for (int g=0 ; g<k ; g++){
            //     cerr << getbit(j, p+1, g);
            // }   cerr << "\n";
            // cerr << i << " " << j << "\n";
            for (int g=0 ; g<k ; g++){
                to+=min(p, getbit(j, p+1, g)+a[i][g])*mypow(p+1, g);
                // dbg(min(p, getbit(j, p+1, g)+a[i][g])*mypow(p+1, g));
            }
            // dbg(to);
            dp[i+1][to]=min(dp[i+1][to], dp[i][j]+c[i]);
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
        }
    }

    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<mypow(p+1, k) ; j++){
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    // output
    if (dp[n][mypow(p+1, k)-1]==INF){
        cout << -1 << "\n";
    }else{
        cout << dp[n][mypow(p+1, k)-1] << "\n";
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