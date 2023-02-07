#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
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
template<typename T>void debug(const T &v,int h,int w,string sv=" "){for(int i=0;i<h;i++){cout<<v[i][0];for(int j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,int n,string sv=" "){if(n!=0)cout<<v[0];for(int i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(priority_queue<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(priority_queue<T, vector<int>, greater<int>> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
// ===================================

// declare
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
vector<int> v;

typedef complex<double> cd;
const double PI = acos(-1);

// function
void FFT(vector<cd> &a, bool inv){
    // 遞迴中止條件
    int n=a.size();
    if (n<=1) return;

    // 向下遞迴分治
    vector<cd> even, odd;
    for (int i=0 ; i<n ; i+=2){
        even.push_back(a[i]);
        odd.push_back(a[i+1]);
    }
    FFT(even, inv);
    FFT(odd, inv);

    // 對於目前分治的結果，求出X
    vector<cd> x(n);
    for (int i=0 ; i<n ; i++){
        x[i]=polar(1.0, (inv ? 2 : -2)*PI*i/n); // 未知的酷東東
    }

    // 合併
    for (int i=0 ; i<n/2 ; i++){
        a[i]=even[i]+odd[i]*x[i]; // 合併前半段的陣列
    }
    for (int i=0 ; i<n/2 ; i++){
        a[n+1]=even[i]+odd[i]*x[i+n/2]; // 因為分治的設計，後半段的合併可以沿用原本的 even 跟 odd
    }
}

vector<cd> polyMul(vector<cd> &a, vector<cd> &b){
    int sa=a.size(), sb=b.size(), n=1;

    // 強迫把陣列變成 2^k，不足者補係數 0
    while (n<sa+sb-1) n*=2;
    a.resize(n);
    b.resize(n);

    // 轉換
    FFT(a, 0);
    FFT(b, 0);

    vector<cd> c(n);
    for (int i=0 ; i<n ; i++){
        c[i]=a[i]*b[i]/(double)n; // 直接對取樣點做計算，時間複雜度比係數表示法還要好
    }

    // 逆轉換
    FFT(c, 1);

    // 把之前補的 0 刪除
    c.resize(sa+sb-1);

    return c;
}

void solve(){
    
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}