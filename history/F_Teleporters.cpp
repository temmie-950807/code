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
// template<typename T>void debug(priority_queue<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
// template<typename T>void debug(priority_queue<T, vector<T>, greater<T>> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(priority_queue<T, vector<T>, greater<T>> st){while(!st.empty()){cerr<<"("<<st.top().F<<", "<<st.top().S<<") ";st.pop();}cerr<<endl;}
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

int n, m, tmp, total;
vector<int> v, p, cnt(MAX_N);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <delta, id>

int f(int len, int seg){ // 線段長度, 切幾段
    if (seg>=len-1) return len;
    int aa=len%(seg+1); // 有多一個的數量
    int bb=(seg+1)-len%(seg+1); // 剛好的數量
    int val=len/(seg+1);
    return aa*(val+1)*(val+1) + bb*val*val;
}

pair<int, int> g(int mid){ // <多幾個傳送器, 用了多少能量>
    // 確保每一段的 cost 不超過 mid
    int ret1=0, ret2=0;
    for (int i=0 ; i<n ; i++){
        int ll=0, rr=p[i], ans=rr;
        while (ll<rr){
            int mid=ll+(rr-ll)/2;
            if (f(p[i], mid)-f(p[i], mid+1)>mid){
                ll=mid+1;
                ans=mid;
            }else{
                rr=mid;
            }
        }
        ret1+=ans;
        ret2+=ans;
        
    }
}

void solve1(){

    // init
    v.push_back(0);

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> m;

    // process
    for (int i=0 ; i<n ; i++){
        int len=v[i+1]-v[i];

        total+=f(len, 0);
        p.push_back(len);
        pq.push({f(len, 1)-f(len, 0), i});
    }

    int ans=0;
    while (total>m){
        ans++;
        total+=pq.top().first;
        int id=pq.top().second;
        pq.pop();

        cnt[id]++;
        pq.push({f(p[id], cnt[id]+1)-f(p[id], cnt[id]), id});
        debug(pq);
    }

    // output
    cout << ans << "\n";
    
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