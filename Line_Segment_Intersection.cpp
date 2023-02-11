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

struct point{
    double x, y;
 
    point operator * (double a){return {x*a, y*a};};
    point operator / (double a){return {x/a, y/a};};
    point operator + (point a){return {x+a.x, y+a.y};};
    point operator - (point a){return {x-a.x, y-a.y};};
    double operator * (point a){return x*a.x+y*a.y;};
    double operator ^ (point a){return {x*a.y-y*a.x};};

    double abs1(){return sqrt(x*x+y*y);};
    double abs2(){return x*x+y*y;};
} a, b, c, d;
 
int sign(double a){
    if (fabs(a)<EPS) return 0;
    return (a>0 ? 1 : -1);
}
 
int ori(point a, point b, point c){
    return sign((b-a)^(c-a));
}
 
bool same_seg(point a, point b, point c){
    return sign((b-a)^(c-a))==0; // 如果 \hat{ab} 跟 \hat{ac} 圍出的平行四邊形面積為 0 則代表共線
}
 
bool btw(point a, point b, point c){
    if (!same_seg(a, b, c)) return 0; // 如果不是共線則直接回傳 false
    return sign((a-c)*(b-c))<=0; // 如果 \hat{ca} 跟 \hat{cb} 相反的，則回傳 false（結果只有可能是 0 或 -1，因為已經判斷是共線了，所以用內積可以找鈍、直、銳角的特性找到結果）
    // 如果是 0：代表 a 跟 c 重疊
    // 如果是 -1：代表 \hat{ab} 跟 \hat{ac} 共線但不同方向
}
 
bool banana(point a, point b, point c, point d){
    int s1=ori(a, b, c);
    int s2=ori(a, b, d);
    int s3=ori(c, d, a);
    int s4=ori(c, d, b);

    if (btw(a, b, c) || btw(a, b, d) || btw(c, d, a) || btw(c, d, b)) return 1; // 如果有點在線裡面，代表一定會相交
    return (s1*s2<0) && (s3*s4<0); // 如果兩個向量「互相」在對面，則回傳 true
}

point banana_pos(point a, point b, point c, point d){
    double x=fabs((b-a)^(c-a)), y=fabs((b-a)^(d-a));
    return (d*x-c*y)/(x-y);
}

point proj(point a, point b, point c){
    return ((b-a)*((b-a)*(c-a)/(b-a).abs2()));
}
 
void solve(){
    // input
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
 
    cout << banana_pos(a, b, c, d).x << " " << banana_pos(a, b, c, d).y << endl;
    // cout << (banana(a, b, c, d) ? "YES\n" : "NO\n");
    // cout << endl;
 
    
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