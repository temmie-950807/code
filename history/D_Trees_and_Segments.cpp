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
bool debug_mode=false;
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
const int MAX_N = 3e3+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, k;
string s;
// pre[i][j] = 只看前綴 i，並使用 j 次操作，可以獲得的最長 0 的長度
vector<vector<int>> pre(MAX_N, vector<int>(MAX_N));
vector<vector<int>> suf(MAX_N, vector<int>(MAX_N));

vector<int> prefix_zero(MAX_N, 0);

// dp[len] = 讓 len 成為最長的 1 字串時，可以產生的最長 0 字串長度
vector<int> dp(MAX_N, 0);

vector<int> ans(MAX_N, 0);

void solve1(){

    // input
    cin >> n >> k;
    cin >> s;

    // init
    fill(prefix_zero.begin(), prefix_zero.begin()+n+1, 0);
    fill(dp.begin(), dp.begin()+n+1, -1);
    fill(ans.begin(), ans.begin()+n+1, 0);

    // 預處理前綴資訊（最長連續 0 一定包含 i）
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<=k ; j++){
            if (s[i]=='0') pre[i][j]=1+(i>0 ? pre[i-1][j] : 0);
            else if (s[i]=='1' && j>0) pre[i][j]=1+(i>0 ? pre[i-1][j-1] : 0);
            else pre[i][j]=0;
        }
    }
    // 預處理後綴資訊（最長連續 0 一定包含 i）
    for (int i=n-1 ; i>=0 ; i--){
        for (int j=0 ; j<=k ; j++){
            if (s[i]=='0') suf[i][j]=1+(i<n-1 ? suf[i+1][j] : 0);
            else if (s[i]=='1' && j>0) suf[i][j]=1+(i<n-1 ? suf[i+1][j-1] : 0);
            else suf[i][j]=0;
        }
    }

    // 預處理前綴資訊（max）
    for (int i=1 ; i<n ; i++){
        for (int j=0 ; j<=k ; j++){
            pre[i][j]=max(pre[i][j], pre[i-1][j]);
        }
    }
    // 預處理後綴資訊(max)
    for (int i=n-2 ; i>=0 ; i--){
        for (int j=0 ; j<=k ; j++){
            suf[i][j]=max(suf[i][j], suf[i+1][j]);
        }
    }

    // 用前綴和維護區間的 0 數量
    for (int i=0 ; i<n ; i++){
        prefix_zero[i]=(s[i]=='0')+(i>0 ? prefix_zero[i-1] : 0);
    }

    // 處理 DP 資訊
    // dp[len] = 如果我有一個全部都是 1 且長度為 len 的 segment，最多可以得到多少的連續 0 的 segment
    for (int i=0 ; i<n ; i++){
        dp[0]=max(dp[0], pre[i][k]);
    }
    for (int l=0 ; l<n ; l++){
        for (int r=l ; r<n ; r++){
            int len=r-l+1;
            int need=prefix_zero[r]-(l>0 ? prefix_zero[l-1] : 0);
            
            if (need>k){ // 要讓區間都變成 1 的成本太高了，直接跳過
                continue;
            }

            dp[len]=max(dp[len], 0LL);
            if (l>0){
                dp[len]=max(dp[len], pre[l-1][k-need]);
            }
            if (r<n-1){
                dp[len]=max(dp[len], suf[r+1][k-need]);
            }
        }
    }

    // 枚舉答案
    for (int i=1 ; i<=n ; i++){ // 枚舉題目要的 a
        for (int j=0 ; j<=n ; j++){ // 枚舉 len
            if (dp[j]!=-1){
                ans[i]=max(ans[i], dp[j]*i+j);
            }
        }
    }

    // output
    for (int i=1 ; i<=n ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    // preview
    cerr << "pre:\n";
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<=k ; j++){
            cerr << pre[i][j] << " ";
        }
        cerr << "\n";
    }

    cerr << "suf:\n";
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<=k ; j++){
            cerr << suf[i][j] << " ";
        }
        cerr << "\n";
    }

    cerr << "dp:\n";
    for (int i=0 ; i<=n ; i++){
        cerr << dp[i] << " ";
    }
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