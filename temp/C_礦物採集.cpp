#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

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
const int MAX_SIZE = 1e6+5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q;
int p, t;
int a, b;
vector<pair<int, int>> v;
int G[2][MAX_SIZE];
int item[3][MAX_SIZE]; // pre, mid, suf

// function
int i, k;
void pre(int x){
    item[0][i++]=x;
    if (G[0][x]!=0) pre(G[0][x]);
    if (G[1][x]!=0) pre(G[1][x]);
}
void mid(int x){
    if (G[0][x]!=0) mid(G[0][x]);
    item[1][i++]=x;
    if (G[1][x]!=0) mid(G[1][x]);
}
void suf(int x){
    if (G[0][x]!=0) suf(G[0][x]);
    if (G[1][x]!=0) suf(G[1][x]);
    item[2][i++]=x;
}

void solve(){
    // input
    cin >> n >> q;
    for (int i=2 ; i<=n ; i++){
        cin >> p >> t;
        G[t][p]=i;
    }
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    debug(G, 2, 15);
    cout << endl << endl;

    // process
    i=0, k=0;
    pre(1);
    i=0, k=0;
    mid(1);
    i=0, k=0;
    suf(1);

    // preview
    debug(item, 3, 15);

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