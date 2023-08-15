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
bool debug_mode=0;
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
const int MAX_N = 1e6+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n;
vector<int> prime, lpf(MAX_N);
vector<int> pow_prime;

// function
void prime_init(){
    for (int i=2 ; i<MAX_N ; i++){
        if (lpf[i]==0){
            lpf[i]=i;
            prime.push_back(i);
        }

        for (auto x : prime){
            if (i*x>=MAX_N) break;
            lpf[i*x]=x;
            if (lpf[i]==x) break;
        }
    }
}

void solve1(){

    // input    
    cin >> n;

    // process
    int ans=0;
    for (int i=0 ; i<pow_prime.size() ; i++){
        for (int j=i+2 ; j<pow_prime.size() ; j++){
            if (pow_prime[i]*pow_prime[j]>n){
                break;
            }

            int p=n/(pow_prime[i]*pow_prime[j]);
            if (p>0){
                cerr << pow_prime[i] << " " << pow_prime[j] << "\n";
                dbg(p);

                if (p>=prime[j]){
                    ans+=(j-i-1);
                    cerr << "add-1: " << j-i-1 << "\n";
                }else if (p<=prime[i]){
                    ans+=0;
                    cerr << "add-2: 0\n";
                }else{
                    
                    int R=upper_bound(prime.begin(), prime.end(), p)-prime.begin();
                    ans+=(R-i-1);
                    cerr << "add-3: " << R-i-1 << "\n";
                }
                cerr << "\n";
            }
        }
    }

    // output
    cout << ans << "\n";
    return;
}

signed main(void){
    fastio;

    prime_init();
    for (auto x : prime){
        pow_prime.push_back(x*x);
    }
    dbg(pow_prime.size());

    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}