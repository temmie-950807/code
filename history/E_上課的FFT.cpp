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
const int MAXN = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
vector<int> v;

// const int MAXN = 262144;
// (must be 2^k)
// before any usage, run pre_fft() first
typedef long double ld;
typedef complex<ld> cplx; //real() ,imag()
const ld PI = acosl(-1);
const cplx I(0, 1);
cplx omega[MAXN+1];
void pre_fft(){
  for(int i=0; i<=MAXN; i++)
    omega[i] = exp(i * 2 * PI / MAXN * I);
}
// n must be 2^k
void fft(int n, cplx a[], bool inv=false){
  int basic = MAXN / n;
  int theta = basic;
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    for (int i = 0; i < mh; i++) {
      cplx w = omega[inv ? MAXN-(i*theta%MAXN)
                         : i*theta%MAXN];
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        cplx x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
    } }
    theta = (theta * 2) % MAXN;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
  if(inv) for (i = 0; i < n; i++) a[i] /= n;
}
cplx arr[MAXN+1];
inline void mul(int _n,ll a[],int _m,ll b[],ll ans[]){
  int n=1,sum=_n+_m-1;
  while(n<sum)
    n<<=1;
  for(int i=0;i<n;i++) {
    double x=(i<_n?a[i]:0),y=(i<_m?b[i]:0);
    arr[i]=complex<double>(x+y,x-y);
  }
  fft(n,arr);
  for(int i=0;i<n;i++)
    arr[i]=arr[i]*arr[i];
  fft(n,arr,true);
  for(int i=0;i<sum;i++)
    ans[i]=(long long int)(arr[i].real()/4+0.5);
}

void solve1(){
    
    string s;
    cin >> s;

    

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