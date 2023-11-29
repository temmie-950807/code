#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma ("O3,unroll-loops")
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
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
int q, a, b;
vector<int> v;

struct segment_tree{

    struct node{
        bool tag=0;
        int ma=0;
        int idx=-1;
    };
    vector<node> arr;

    void init(int n){
        arr.resize(n<<3);
    }

    node pull(node A, node B){ // 計算新的資訊
        node C;
        if (A.ma>=B.ma){
            C.ma=A.ma;
            C.idx=A.idx;
        }else{
            C.ma=B.ma;
            C.idx=B.idx;
        }
        return C;
    }

    void push(int idx){ // 將 tag 向下推
        if (arr[idx].tag){
            arr[idx].ma=MOD-arr[idx].ma;
        }
        arr[idx*2+1].tag^=arr[idx].tag;
        arr[idx*2+2].tag^=arr[idx].tag;
        arr[idx].tag=0;
    }

    void build(vector<int> &v, int idx=0, int ll=0, int rr=n){
        if (rr-ll==1){
            arr[idx].ma=v[ll];
            arr[idx].idx=ll;
        }else{
            int mid=(ll+rr)/2;
            build(v, idx*2+1, ll, mid);
            build(v, idx*2+2, mid, rr);
            arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
        }
    }

    void modify(int ql, int qr, int val, int idx=0, int ll=0, int rr=n){
        push(idx);
        if (rr<=ql || qr<=ll) return;
        if (ql<=ll && rr<=qr){
            arr[idx].tag^=1;
            push(idx);
            return;
        }
        int mid=(ll+rr)/2;
        modify(ql, qr, idx*2+1, ll, mid);
        modify(ql, qr, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }

    node query(int ql, int qr, int idx=0, int ll=0, int rr=n){
        push(idx);
        if (rr<=ql || qr<=ll) return node();
        if (ql<=ll && rr<=qr) return arr[idx];

        int mid=(ll+rr)/2;
        return pull(query(ql, qr, idx*2+1, ll, mid), query(ql, qr, idx*2+2, mid, rr));
    }
};

void solve1(){

    // init
    v.clear();
    segment_tree ST;

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // process
    ST.init(n);
    ST.build(v);

    // queries
    int ans=0;
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;
        a--;
        ST.modify(a, b, MOD-1);

        // preview
        int idx=ST.query(0, n).idx+1;
        ans+=idx;
    }

    // output
    cout << ans;
    
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    for (int i=1 ; i<=t ; i++){
        cout << "Case #" << i << ": ";
        solve1();
        cout << "\n";
    }
    return 0;
}