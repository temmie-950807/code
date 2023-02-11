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
const int MAX_SIZE = 1e3+5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

struct point{
    double x, y;

    // 純量乘法
    point operator * (int a){return {a*x, a*y};};
    point operator / (int a){return {a/x, a/y};};

    // 向量加減法
    point operator + (point a){return {x+a.x, y*a.y};};
    point operator - (point a){return {x-a.x, y-a.y};};

    // 內積&外積
    double operator * (point a){return x*a.x+y*a.y;};
    double operator ^ (point a){return x*a.y-y*a.x;};

    // 大小
    double len(){return sqrt(x*x+y*y);};
};

int sign(double a){ // 正負: 1=正數, 0=0, -1=負數
    if (abs(a)<EPS) return 0;
    else return (a>0 ? 1 : -1);
}

int ori(point a, point b, point c){ // 方向: 1=順時鐘, 0=重疊, -1=逆時鐘
    return sign((c-a)^(b-a));
}

int n, m, x, y;
vector<point> p(MAX_SIZE);

bool same_seg(point a, point b, point c){
    return sign((c-a)^(b-a))==0; // 如果平行四邊形面積為 0 則為共線
}

bool btw_seg(point a, point b, point c){
    if (same_seg(a, b, c)==false) return false; // 如果不共線就絕對是 false
    return (a-c)*(b-c)<=0; // 如果互相在對面，則回傳 true
}

bool cross_seg(point a, point b, point c, point d){
    int s1=ori(a, b, c);
    int s2=ori(a, b, d);
    int s3=ori(c, d, a);
    int s4=ori(c, d, b);

    if (btw_seg(a, b, c) || btw_seg(a, b, d) || btw_seg(c, d, a) || btw_seg(c, d, b)) return true;
    return s1*s2<0 && s3*s4<0; // 確保互相在對面
}

void solve(){
    // input
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> p[i].x >> p[i].y;
    }

    // queries
    for (int i=0 ; i<m ; i++){
        cin >> x >> y;
    }
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}