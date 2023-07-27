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
typedef pair<int, int> pii;

int id=1;

struct line{
    double x, y;
    line(double x1, double y1) : x(x1), y(y1) {}
    line(double x1, double y1, double x2, double y2) : x(x2-x1), y(y2-y1) {}

    line operator * (double a) {return {x*a, y*a};}
    line operator / (double a) {return {x/a, y/a};}
    
    line operator + (line a) {return {x+a.x, y+a.x};}
    line operator - (line a) {return {x-a.x, y-a.x};}
    
    double operator * (line a) {return x*a.x+y*a.x;}
    double operator ^ (line a) {return x*a.y-y*a.x;}
};

int sign(double a){
    if (fabs(a)<EPS) return 0;
    else if (a<0) return -1;
    else return 1;
}

int ori(line a, line b){ // 1: 左轉, 0: 相交, -1: 右轉
    return sign(a^b);
}

int a, b, c, d, e, f, g, h;

void solve1(){

    // input
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    line l1(a, b, c, d);
    line l2(a, b, e, f);
    line l3(a, b, g, h);

    line p1(e, f, g, h);
    line p2(e, f, a, b);
    line p3(e, f, c, d);

    if (ori(l1, l2)==0 || ori(l1, l3)==0 || ori(p1, p2)==0 || ori(p1, p3)==0){
        // 有任意一點在線上
        cout << "YES\n";
    }else if (ori(l1, l2)!=ori(l1, l3) && ori(p1, p2)!=ori(p1, p3)){
        // 兩線相交
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
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