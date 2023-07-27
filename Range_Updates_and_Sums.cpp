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
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q, tmp;
vector<int> v;
int op, a, b, c;

// [ll, rr), based-0
// 使用前記得 init(陣列大小), build(陣列名稱)
// add(ll, rr): 區間修改
// set(ll, rr): 區間賦值
// query(ll, rr): 區間求和 / 求最大值
struct segment_tree{
    struct node{
        int add_tag=0;
        int set_tag=0;
        int sum=0;
        int ma=0;
    };
 
    vector<node> arr;
 
    void init(int n){
        arr.resize(n<<2);
    }
 
    node pull(node A, node B){
        node C;
        C.sum=A.sum+B.sum;
        C.ma=max(A.ma, B.ma);
        return C;
    }
 
    void push(int idx, int ll, int rr){
        if (arr[idx].set_tag>0){
            // set 優先實作
            arr[idx].sum=(rr-ll)*arr[idx].set_tag;
            arr[idx].ma=arr[idx].set_tag;
 
            if (rr-ll>1){
                arr[idx*2+1].add_tag=0;
                arr[idx*2+1].set_tag=arr[idx].set_tag;
                arr[idx*2+2].add_tag=0;
                arr[idx*2+2].set_tag=arr[idx].set_tag;
            }
 
            arr[idx].set_tag=0;
        }
        if (arr[idx].add_tag>0){
            // add 次要實作
            arr[idx].sum+=(rr-ll)*arr[idx].add_tag;
            arr[idx].ma+=arr[idx].add_tag;
 
            if (rr-ll>1){
                arr[idx*2+1].add_tag+=arr[idx].add_tag;
                arr[idx*2+2].add_tag+=arr[idx].add_tag;
            }
 
            arr[idx].add_tag=0;
        }
    }
 
    void build(vector<int> &v, int idx=0, int ll=0, int rr=n){
        if (rr-ll==1){
            arr[idx].sum=v[ll];
            arr[idx].ma=v[ll];
        }else{
            int mid=(ll+rr)/2;
            build(v, idx*2+1, ll, mid);
            build(v, idx*2+2, mid, rr);
            arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
        }
    }
 
    void add(int ql, int qr, int val, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return;
        if (ql<=ll && rr<=qr){
            arr[idx].add_tag+=val;
            push(idx, ll, rr);
            return;
        }
        int mid=(ll+rr)/2;
        add(ql, qr, val, idx*2+1, ll, mid);
        add(ql, qr, val, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }
 
    void set(int ql, int qr, int val, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return;
        if (ql<=ll && rr<=qr){
            arr[idx].add_tag=0;
            arr[idx].set_tag=val;
            push(idx, ll, rr);
            return;
        }
        int mid=(ll+rr)/2;
        set(ql, qr, val, idx*2+1, ll, mid);
        set(ql, qr, val, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }
 
    node query(int ql, int qr, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return node();
        if (ql<=ll && rr<=qr) return arr[idx];
 
        int mid=(ll+rr)/2;
        return pull(query(ql, qr, idx*2+1, ll, mid), query(ql, qr, idx*2+2, mid, rr));
    }
} ST;

void solve1(){
    
    // input
    cin >> n >> q;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // build
    ST.init(n);
    ST.build(v);

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> op;

        if (op==1){
            cin >> a >> b >> c;
            a--;
            ST.add(a, b, c);

        }else if (op==2){
            cin >> a >> b >> c;
            a--;
            ST.set(a, b, c);

        }else if (op==3){
            cin >> a >> b;
            a--;
            cout << ST.query(a, b).sum << "\n";
        }
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