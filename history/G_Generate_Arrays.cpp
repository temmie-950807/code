#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
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
const int MAX_N = 2e5+5;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q, tmp;
int cmd, s, x;
vector<int> v;
order_set ss[MAX_N][2];
// vector<vector<order_set>> ss(MAX_N, vector<order_set>(2));

// fast IO
inline char readchar(){
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}
inline int nextint(){
    int x = 0, c = readchar(), neg = false;
    while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
    if(c == '-') neg = true, c = readchar();
    while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
    if(neg) x = -x;
    return x; // returns 0 if EOF
}

// 0 -> {index, value}
// 1 -> {value, index}

void solve1(){
    
    // input
    n=nextint();
    for (int i=0 ; i<n ; i++){
        tmp=nextint();
        ss[0][0].insert({i, tmp});
        ss[0][1].insert({tmp, i});
    }

    // queries
    q=nextint();
    for (int i=1 ; i<=q ; i++){
        cmd=nextint();
        s=nextint();
        x=nextint();

        if (cmd==1){
            // 前 x 留在 s，其他的去 i
            int sz=ss[s][0].size();
            x=min(x, sz);
            if (2*x<=sz){
                // 要拿走的東西比較少
                for (int j=0 ; j<x ; j++){
                    auto it=ss[s][0].begin();
                    ss[i][0].insert(*it);
                    ss[i][1].insert({it->second, it->first});
                    ss[s][1].erase({it->second, it->first});
                    ss[s][0].erase(it);
                }
                ss[i][0].swap(ss[s][0]);
                ss[i][1].swap(ss[s][1]);
            }else{
                // 要拿走的東西比較多
                for (int j=0 ; j<sz-x ; j++){
                    auto it=prev(ss[s][0].end());
                    ss[i][0].insert(*it);
                    ss[i][1].insert({it->second, it->first});
                    ss[s][1].erase({it->second, it->first});
                    ss[s][0].erase(it);
                }
            }

        }else if (cmd==2){
            // 小於等於 x 的留在 s，其他的去 i
            int sz=ss[s][1].size();
            x=ss[s][1].order_of_key({x, MAX_N});
            if (2*x<=sz){
                // 要拿走的東西比較少
                for (int j=0 ; j<x ; j++){
                    auto it=ss[s][1].begin();
                    ss[i][1].insert(*it);
                    ss[i][0].insert({it->second, it->first});
                    ss[s][0].erase({it->second, it->first});
                    ss[s][1].erase(it);
                }
                ss[i][0].swap(ss[s][0]);
                ss[i][1].swap(ss[s][1]);
            }else{
                // 要拿走的東西比較多
                for (int j=0 ; j<sz-x ; j++){
                    auto it=prev(ss[s][1].end());
                    ss[i][1].insert(*it);
                    ss[i][0].insert({it->second, it->first});
                    ss[s][0].erase({it->second, it->first});
                    ss[s][1].erase(it);
                }
            }
        }

        // output
        cout << ss[i][1].size() << "\n";
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