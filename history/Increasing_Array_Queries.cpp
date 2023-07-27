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

int n, q, a, b;
vector<int> v;

struct Segment_Tree{
    struct node{
        int ma=0;
        int sum=0;
    };

    vector<node> arr;

    void init(int sz){
        arr.resize(sz<<2);
    }

    node pull(node &A, node &B){
        node C;
        C.ma=max(A.ma, B.ma);
        C.sum=A.ma+B.ma;
    }

    void build(vector<int> &v, int idx=0, int ll=0, int rr=n){
        if (rr-ll==1){
            arr[idx].ma=v[ll];
            arr[idx].sum=v[ll];
            return;
        }

        int mid=ll+(rr-ll)/2;
        build(v, idx*2+1, ll, mid);
        build(v, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }
    
    void update(int pos, int val, int idx=0, int ll=0, int rr=n){
        if (rr-ll==1){
            arr[idx].ma=val;
            arr[idx].sum=val;
            return;
        }

        int mid=ll+(rr-ll)/2;
        if (pos<mid) update(pos, val, idx*2+1, ll, mid);
        else update(pos, val, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }

    node query(int ql, int qr, int pre_ma, int idx=0, int ll=0, int rr=n){
        if (rr<=ql || qr<=ll) return {-INF, -INF};
        else if (ql<=ll && rr<=qr){
            if (arr[idx].ma>pre_ma) return {arr[idx]};
            else return {pre_ma, pre_ma};
        }else{
            if (pre_ma>arr[idx].ma){
                return {pre_ma, (rr-ll)*pre_ma};
            }

            int mid=ll+(rr-ll)/2;
            query()
        }

    }
};


void solve1(){

    // input
    cin >> n >> a;
    for (int i=0 ; i<n ; i++){
        cin >> a;
        v.push_back(a);
    }

    // process
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        a--;
        b--;
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