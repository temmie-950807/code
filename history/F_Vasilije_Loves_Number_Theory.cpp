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
const int MAX_N = 1e6+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int nn, q, op, x;
vector<int> prime, lpf(MAX_N);

int ori_val, val;
map<int, int> ori, now, pre;

void prime_init(){
    for (int i=2 ; i<MAX_N ; i++){
        if (lpf[i]==0){
            lpf[i]=i;
            prime.push_back(i);
        }

        for (int j : prime){
            if (i*j>=MAX_N) break;
            lpf[i*j]=j;
            if (lpf[i]==j) break;
        }
    }
}

void p(int n, map<int, int> &rec){
    rec.clear();
    for (auto x : prime){
        while (n%x==0){
            rec[x]++;
            n/=x;
        }
    }
    if (n>1){
        rec[n]++;
    }
}

void reset(){
    now=ori;
    val=ori_val;
}

void solve1(){

    // init
    nn=0;
    ori.clear();
    ori_val=1;

    // input
    cin >> nn >> q;
    p(nn, ori); // 紀錄一開始的質因數分解
    for (auto x : ori){ // 紀錄 d(n)
        ori_val*=(x.second+1);
    }
    reset();

    // debug(now);
    // dbg(val);
    // cerr << "\n";

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> op;

        if (op==1){
            // modify and answer
            cin >> x;
            p(x, pre);

            for (auto x : pre){
                if (now.find(x.first)==now.end()){
                    now[x.first]=x.second;
                    val*=(x.second+1);
                }else{
                    val/=(now[x.first]+1);
                    now[x.first]+=x.second;
                    val*=(now[x.first]+1);
                }
            }

            // answer
            p(val, pre);
            bool flag=1;
            for (auto x : pre){
                if (now.find(x.first)==now.end()){
                    flag=0;
                    break;
                }else{
                    if (now[x.first]<x.second){
                        flag=0;
                        break;
                    }
                }
            }
            if (flag){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }

        }else{
            // reset
            reset();

        }

        // debug(now);
        // dbg(val);
        // cerr << "\n";
    }
    cout << "\n";
    
    return;
}

signed main(void){
    fastio;

    prime_init();
    
    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }
    return 0;
}