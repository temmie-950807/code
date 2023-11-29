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
const int MAX_N = 500+5;
const int INF = 2e18;
const int MOD = 998244353;
const double EPS = 1e-6;

int n, s, K, tmp;
vector<vector<int>> v(MAX_N);
vector<vector<pair<int, int>>> pos(MAX_N, vector<pair<int, int>>(255));

void update(vector<int> &v, int pos, int val){
    pos++;
    for (int i=pos ; i<v.size() ; i+=i&-i){
        v[i]+=val;
        v[i]%=MOD;
    }
}

int query(vector<int> &v, int pos){
    pos++;
    int ret=0;
    for (int i=pos ; i>0 ; i-=i&-i){
        ret+=v[i];
        ret%=MOD;
    }
    return ret;
}

void solve1(){
    
    // input
    cin >> n >> s >> K;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<s ; j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
        sort(v[i].begin(), v[i].end());
    }
    v[n]=v[0];

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<s ; j++){
            int ll=lower_bound(v[i+1].begin(), v[i+1].end(), v[i][j]-K)-v[i+1].begin();
            int rr=upper_bound(v[i+1].begin(), v[i+1].end(), v[i][j]+K)-v[i+1].begin();
            pos[i][j]={ll, rr};
        }
    }

    // process
    int total=0;
    for (int x=0 ; x<s ; x++){
        vector<vector<int>> dp(MAX_N, vector<int>(255));
        update(dp[0], x, 1);
        update(dp[0], x+1, MOD-1);
        for (int i=0 ; i<n ; i++){

            for (int j=0 ; j<s ; j++){
                // 區間加值, 單點查詢
                if (pos[i][j].first!=pos[i][j].second){
                    int add=query(dp[i], j);
                    update(dp[i+1], pos[i][j].first, add);
                    update(dp[i+1], pos[i][j].second, MOD-add);
                }
            }
        }

        int add=query(dp[n], x);
        total+=add;
        total%=MOD;
    }

    // output
    cout << total << "\n";

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