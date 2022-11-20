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
const int MAX_SIZE = 1e5+5;
const __int128_t INF = 6e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, k;
vector<int> ans;
vector<__int128_t> cc(1), pp(1);
const int num[3]={1, -1, 0};

// function
void solve(){

    // init
    ans.clear();
    cc.resize(1, 0);
    pp.resize(1, 0);
    for (int i=1 ; pp.back()+i<=9*INF ; i*=3){
        cc.push_back(i);
        pp.push_back(pp.back()+cc.back());
    }
    // cout << cc.size() << endl;
    // debug(cc);
    // cout << pp.size() << endl;
    // debug(pp);

    // input
    cin >> n;

    if (n==0){
        cout << 1 << endl << 0 << endl;
        return;
    }

    for (int i=0 ; i<pp.size() ; i++){
        if (pp[i]>=abs(n)){
            k=i;
            break;
        }
    }

    for (int i=1, j=1 ; i<=k ; i++, j*=3){
        ans.push_back(num[(abs(n)-pp[i-1]-1)%cc[i+1]/cc[i]]);
        // cout << ans.back() << " ";
    }

    // cout << endl << endl;

    // output
    cout << ans.size() << endl;
    for (int x : ans){
        if (n<0){
            cout << -1*x << " ";
        }else{
            cout << x << " ";
        }
    }
    cout << endl;
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