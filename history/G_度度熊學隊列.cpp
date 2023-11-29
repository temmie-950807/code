#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define F first
#define S second
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
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q;
int op, u, v, w, val;

struct linked_list{
    struct node{
        int val=0;
        node* pre=nullptr;
        node* suf=nullptr;
    };

    node head;
    node tail;

    void push_front(int val){
        node now;
        now.val=val;

        now.pre=&head;
        now.suf=head.suf;
        head.suf->pre=&now;
        head.suf=&now;
    }

    void push_back(int val){
        node now;
        now.val=val;

        now.pre=tail.pre;
        now.suf=&tail;
        tail.pre->suf=&now;
        tail.pre=&now;
    }

    int pop_front(){
        if (head.suf==&tail) return -1;
        int ret=head.suf->val;

        head.suf->suf->pre=&head;
        head.suf=head.suf->suf;

        return ret;
    }

    int pop_back(){
        if (head.suf==&tail) return -1;
        int ret=tail.pre->val;

        tail.pre->pre->suf=&tail;
        tail.pre=tail.pre->pre;

        return ret;
    }

    void clear(){
        // head =new node();
        // tail=new node();
    }

    void merge_normal(vector<linked_list> &l, int u, int v){
        l[u].tail.suf=&l[v].head;
        l[v].head.pre=&l[u].tail;
        l[v].clear();
    }

    void merge_reverse(vector<linked_list> &l, int u, int v){
        l[u].tail.suf=&l[v].head;
        l[v].head.pre=&l[u].tail;
        l[v].clear();
    }
};

void solve1(){

    // input
    cin >> n >> q;

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> op;

        switch (op){
            case 1:
                // 在編號 u 的 deque 加上 val （w = 0 最前面，否則反之）
                cin >> u >> w >> val;

                break;
            case 2:
                // 在編號 u 的 deque 刪除元素 （w = 0 最前面，否則反之）
                cin >> u >> w;

                break;
            case 3:
                // 編號 v 的 deque 接在 u 的後面 （w = 1 就要先把 v 反轉）
                cin >> u >> v >> w;

                break;
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