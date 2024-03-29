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

struct Data{
    int val=0;
    vector<int> ptr;
};

struct cmp{
    bool operator () (Data &A, Data &B){
        return A.val<B.val;
    }
};

int n, c, tmp;
int m;
vector<vector<int>> v;
set<vector<int>> aa, bb;
priority_queue<Data, vector<Data>, cmp> pq;

void solve1(){

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        v.push_back(vector<int>());
        cin >> c;
        for (int j=0 ; j<c ; j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    cin >> m;
    for (int i=0 ; i<m ; i++){
        vector<int> add;
        for (int j=0 ; j<n ; j++){
            cin >> tmp;
            add.push_back(--tmp);
        }
        aa.insert(add);
    }

    // process
    Data d;
    for (int i=0 ; i<n ; i++){
        d.val+=v[i].back();
        d.ptr.push_back(v[i].size()-1);
    }
    pq.push(d);

    while (1){
        Data now=pq.top();
        pq.pop();

        if (aa.find(now.ptr)==aa.end()){
            for (auto x : now.ptr){
                cout << x+1 << " ";
            }
            cout << "\n";
            return;
        }else{
            for (int i=0 ; i<n ; i++){
                if (now.ptr[i]!=0){
                    Data nxt=now;
                    nxt.val-=v[i][nxt.ptr[i]];
                    nxt.ptr[i]--;
                    nxt.val+=v[i][nxt.ptr[i]];

                    if (bb.find(nxt.ptr)==bb.end()){
                       pq.push(nxt);
                       bb.insert(nxt.ptr);
                    }
                }
            }
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