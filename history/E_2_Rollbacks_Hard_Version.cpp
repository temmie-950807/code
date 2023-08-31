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
const int MAX_N = 1e6+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int q, x, ptr=0;
char c;
vector<int> BIT(MAX_N); // 維護每個值的最低出現時間點
vector<int> a(MAX_N, -1); // 依照時間點操作的值
vector<set<int>> ss(MAX_N); // 維護每個值出現的時間點
vector<pair<int, int>> change; // 最後的操作 <+/-, 原本的值/>

// function
void update(int pos, int val){
    for (int i=pos ; i<MAX_N ; i+=i&-i){
        BIT[i]+=val;
    }
}

int query(int pos){
    if (pos<=0) return 0;
    int ret=0;
    for (int i=pos ; i>0 ; i-=i&-i){
        ret+=BIT[i];
    }
    return ret;
}

void solve1(){

    // input
    cin >> q;

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> c;

        if (c=='+'){
            cin >> x;
            ptr++;
            change.push_back({1, a[ptr]});

            if (a[ptr]!=-1){
                if (ss[a[ptr]].size()){ // 仍然保有之前的資訊，因此先撤銷
                    update(*ss[a[ptr]].begin(), -1);
                    ss[a[ptr]].erase(ptr);
                }
                if (ss[a[ptr]].size()){ // 刪除了該時間（ptr）點的操作，該數值還有其他操作
                    update(*ss[a[ptr]].begin(), 1);
                }
            }
            a[ptr]=x;
            {
                if (ss[a[ptr]].size()){ // 撤銷之前的操作
                    update(*ss[a[ptr]].begin(), -1);
                }
                ss[a[ptr]].insert(ptr);
                if (ss[a[ptr]].size()){ // 更新最新的「時間（ptr）最早的操作」
                    update(*ss[a[ptr]].begin(), 1);
                }
            }

        }else if (c=='-'){
            cin >> x;
            ptr-=x;
            change.push_back({-1, x});

        }else if (c=='!'){
            if (change.back().first==1){
                if (a[ptr]!=-1){
                    if (ss[a[ptr]].size()){ // 仍然保有之前的資訊，因此先撤銷
                        update(*ss[a[ptr]].begin(), -1);
                        ss[a[ptr]].erase(ptr);
                    }
                    if (ss[a[ptr]].size()){ // 刪除了該時間（ptr）點的操作，該數值還有其他操作
                        update(*ss[a[ptr]].begin(), 1);
                    }
                }

                a[ptr]=change.back().second;
                if (a[ptr]!=-1){
                    if (ss[a[ptr]].size()){ // 撤銷之前的操作
                        update(*ss[a[ptr]].begin(), -1);
                    }
                    ss[a[ptr]].insert(ptr);
                    if (ss[a[ptr]].size()){ // 更新最新的「時間（ptr）最早的操作」
                        update(*ss[a[ptr]].begin(), 1);
                    }
                }
                ptr--;

            }else{
                ptr+=change.back().second;
            }
            change.pop_back();

        }else if (c=='?'){
            cout << query(ptr) << "\n";
            cout.flush();

        }

        // cerr << "ptr: " << ptr << "\n";
        // for (int i=1 ; i<=5 ; i++){
        //     cerr << a[i] << " ";
        // }
        // cerr << "\n\n";
        // cerr.flush();

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