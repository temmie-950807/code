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
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, k, q;
int l, r, s;
map<int, int> ss;
vector<pair<int, int>> wa;

// function
void split(map<int, int> &ss, int pos){
    auto it=ss.lower_bound(pos);
    if (it->first != pos){ // 尋找有沒有pos這個紀錄
        // 如果沒有就去找目前的值是多少，並且新增進去
        int tmp=prev(it)->second;
        ss[pos]=tmp;
    }

}

void ins(map<int, int> &ss, int l, int r, int val){
    auto it_l=ss.find(l);
    auto it_r=ss.find(r);

    for (auto it=it_l ; it!=it_r ; it++){
        if (it->second && val>=it->second){
            wa.push_back({it->first, 1});
            wa.push_back({next(it)->first, -1});
        }
    }

    it_l->second=s;
    ss.erase(next(it_l), it_r);
}

void solve(){
    // input
    cin >> n >> k >> q;

    // init
    wa.clear();
    ss.clear();
    ss.insert({0, 0});
    ss.insert({n+1, 0});
    // 維護的為: {x, v}在[x, next(x))都是v

    // operation
    for (int i=0 ; i<q ; i++){
        cin >> l >> r >> s;
        r++;

        split(ss, l);
        split(ss, r);
        ins(ss, l, r, s);
    }

    // get answer
    int ans=0, now=0;
    sort(wa.begin(), wa.end());

    for (auto it=ss.begin() ; it->first!=n+1 ; it++){
        if (it->second>0){
            // 把所有覆蓋過的區間先加入答案
            ans+=next(it)->first-it->first;
        }
    }

    for (int i=0 ; i<(int)wa.size()-1 ; i++){
        now+=wa[i].second;
        if (now>0){
            ans-=wa[i+1].first-wa[i].first;
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

