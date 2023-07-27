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

const int A=48763, B=1e9+7;
int n;
string g, s, k;
vector<int> h1(MAX_N), h2(MAX_N), p(MAX_N);
 
int get_value1(int l, int r){ // [l, r]
    if (l==0) return h1[r];
    return (h1[r]-h1[l-1]*p[r-l+1]%B+B)%B;
}
 
int get_value2(int l, int r){ // [l, r]
    if (l==0) return h2[r];
    return (h2[r]-h2[l-1]*p[r-l+1]%B+B)%B;
}
 
bool check(int i, int mid){
    return get_value1(i-mid, i)==get_value2(n-i-1-mid, n-i-1);
}
 
void solve1(){
 
    // input
    cin >> n >> g;
    g=g+g;

    for (int _=0 ; _<g.size()/2 ; _++){
        
        // init
        cerr << "_: " << _ << "\n";
        s=g.substr(_, n);
        dbg(n);
        dbg(s);
        k="";

        for (int i=0 ; i<s.size() ; i++){
            if (i) k+='#';
            k+=s[i];
        }
        string tmp_k=k;
        reverse(tmp_k.begin(), tmp_k.end());
        int tmp_n=k.size();
    
        // build
        for (int i=0 ; i<tmp_n ; i++){
            if (i==0){
                h1[i]=k[i];
                h2[i]=tmp_k[i];
                p[i]=1;
            }else{
                h1[i]=(h1[i-1]*A+k[i])%B;
                h2[i]=(h2[i-1]*A+tmp_k[i])%B;
                p[i]=(p[i-1]*A)%B;
            }
        }
    
        // process
        int mi=0, pos=0;
        for (int i=0 ; i<tmp_n ; i++){
            int ll=0, rr=min(i+1, tmp_n-i), ans=min(i+1, tmp_n-i)-1;
    
            while (ll<rr){
                int mid=ll+(rr-ll)/2;
    
                if (check(i, mid)){
                    ll=mid+1;
                    ans=mid;
                }else{
                    rr=mid;
                }
            }
    
            if (ans>mi){
                mi=ans;
                pos=i;
            }
        }
    
        // output
        if (pos%2==0){
            pos/=2;
            mi/=2;
            cout << s.substr(pos-mi, mi*2+1) << endl;
        }else{
            pos/=2;
            mi=(mi+1)/2;
            cout << s.substr(pos-mi+1, mi*2) << endl;
        }
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