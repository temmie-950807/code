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

struct trans{
    int l, a, b, r;

    bool operator < (const trans B){
        if (b==B.b){
            return l<B.l;
        }else{
            return b>B.b;
        }
    }

    void preview(){
        cerr << "[" << l << " [" << a << ", " << b << "] " << r << "]\n";
    }
} tt;

int n, l, a, b, r;
vector<trans> v;

int id=0;
vector<pair<int, int>> ss;
vector<int> far_point;

/*
預處理在每個區間最多可以到哪裡（用 set）
*/

void solve1(){

    // init
    v.clear();
    ss.clear();
    id=0;
    far_point.clear();

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tt.l >> tt.r >> tt.a >> tt.b;
        v.push_back(tt);
    }

    sort(v.begin(), v.end());
    for (auto x : v){
        x.preview();
    }
    cerr << "\n";

    for (auto x : v){
        auto it1=lower_bound(ss.begin(), ss.end(), make_pair(-x.r, -INF));
        auto it2=lower_bound(ss.begin(), ss.end(), make_pair(-x.l, -INF));
        dbg(it2-it1);

        if (it2-it1>0){
            // 找到有可能到的更遠的點
            ss.push_back(make_pair(-x.l, (*prev(it2)).second));

        }else{
            // 不可能再到更遠的點
            ss.push_back(make_pair(-x.r, id));
            ss.push_back(make_pair(-x.l, id));
            id++;
            far_point.push_back(x.b);
        }
    }

    cerr << "ss: \n";
    for (auto x : ss){
        cerr << x.first << " " << x.second << "\n";
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