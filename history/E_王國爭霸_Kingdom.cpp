#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
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
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n;
int x, y, p, tmp;
int q;
int cmd, a, b, c, d;
vector<int> v;

#define cont pair<deque<pair<int, int>>, deque<pair<int, int>>>
map<pair<int, int>, cont> ss;

void balance(cont &ss){

    while (!(ss.first.size()==ss.second.size() || ss.first.size()==ss.second.size()+1)){
        if (ss.first.size()>ss.second.size()){
            ss.second.push_front(ss.first.back());
            ss.first.pop_back();
        }else{
            ss.first.push_back(ss.second.front());
            ss.second.pop_front();
        }
    }
}

void solve1(){

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> x >> y >> p;

        for (int i=0 ; i<p ; i++){
            cin >> tmp;
            ss[{x, y}].first.push_back({i, tmp});
        }
        balance(ss[{x, y}]);
    }

    // queries
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> cmd;

        if (cmd==1){
            // oldest soldier died
            cin >> a >> b;
            if (ss[{a, b}].second.size()){
                ss[{a, b}].second.pop_back();
            }else{
                ss[{a, b}].first.pop_back();
            }
            balance(ss[{a, b}]);

        }else if (cmd==2){
            // youngest soldier died
            cin >> a >> b;
            ss[{a, b}].first.pop_front();
            balance(ss[{a, b}]);

        }else if (cmd==3){
            // spawn a new soldier
            cin >> a >> b >> c;
            ss[{a, b}].first.push_front({ss[{a, b}].first.begin()->first-1, c});
            balance(ss[{a, b}]);

        }else if (cmd==4){
            // war start
            cin >> a >> b >> c >> d;
            pair<int, int> A=ss[{a, b}].first.back();
            pair<int, int> B=ss[{c, d}].first.back();

            if (A.second==B.second){
                continue;
            }else if (A.second>B.second){
                ss[{a, b}].first.back().second+=B.second;
                ss[{c, d}].first.pop_back();
                balance(ss[{c, d}]);
            }else{
                ss[{a, b}].first.pop_back();
                ss[{c, d}].first.back().second+=A.second;
                balance(ss[{a, b}]);
            }

            // 5 -> 0 1 2 3 4
            // 4 -> 0 1 2 3
        }
    }

    // output
    for (auto x : ss){
        cout << x.first.first << " " << x.first.second << "\n";
        cout << x.second.first.size()+x.second.second.size() << " ";
        for (auto y : x.second.first){
            cout << y.second << " ";
        }
        for (auto y : x.second.second){
            cout << y.second << " ";
        }
        cout << "\n";
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