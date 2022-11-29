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

struct matrix{
    int n, m;
    vector<vector<int>> arr;

    matrix(int _n=1, int _m=1){
        n=_n;
        m=_m;
        arr.resize(n, vector<int>(m, 0));
    }

    void print(){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix operator * (matrix B){
        matrix ret(n, B.m);

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<B.m ; j++){
                for (int k=0 ; k<m ; k++){
                    ret.arr[i][j]+=arr[i][k]*B.arr[k][j];
                }
            }
        }

        return ret;
    }
};

int n, m, q;
int x, y, op, p, a, b;
vector<int> v;
vector<matrix> ip(1), pre;

void solve(){
    // init
    matrix mat(3, 3);
    mat.arr={{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    pre.push_back(mat);

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        matrix mat(1, 3);
        cin >> x >> y;
        mat.arr={{x, y, 1}};
        ip.push_back(mat);
    }

    // operation
    cin >> m;
    for (int i=0 ; i<m ; i++){
        matrix mat(3, 3);
        cin >> op;
        if (op==3 || op==4) cin >> p;
        
        if (op==1){
            mat.arr={{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
        }else if (op==2){
            mat.arr={{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
        }else if (op==3){
            mat.arr={{-1, 0, 0}, {0, 1, 0}, {2*p, 0, 1}};
        }else if (op==4){
            mat.arr={{1, 0, 0}, {0, -1, 0}, {0, 2*p, 1}};
        }
        pre.push_back(pre.back()*mat);
    }
    
    // queries
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        
        matrix mat=ip[b]*pre[a];
        cout << mat.arr[0][0] << " " << mat.arr[0][1] << endl;
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