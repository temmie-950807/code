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
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;

int n, k, tmp;
int cnt;
vector<int> v(MAX_SIZE), G[MAX_SIZE], dep(MAX_SIZE);

// function
void dfs(int x, int mid){
    for (auto y : G[x]){
        dfs(y, mid);
        dep[x]=max(dep[x], dep[y]);
    }

    if (x!=1) dep[x]++;

    if (dep[x]==mid && v[x]!=1){
        cnt++;
        dep[x]=0;
    }
}

bool check(int mid){ // 是否可以在k步裡面小於等於x高度
    // init
    cnt=0;
    for (int i=0 ; i<=n ; i++){
        dep[i]=0;
    }

    // dfs
    dfs(1, mid);

    return cnt<=k;
}

void solve(){
    // init
    cin >> n >> k;
    for (int i=0 ; i<=n ; i++){
        G[i].clear();
    }

    // input
    v[1]=1;
    for (int i=2 ; i<=n ; i++){
        cin >> v[i];
        G[v[i]].push_back(i);
    }

    // binary search
    int l=1, r=n, mid, ans=INF; // [l, r)
    while (l<r){
        // init
        mid=l+(r-l)/2;

        // move
        if (check(mid)==1){
            ans=min(ans, mid);
            r=mid;
        }else{
            l=mid+1;
        }
    }

    // output
    cout << ans << endl;
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