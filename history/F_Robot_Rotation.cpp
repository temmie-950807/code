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

/*
觀察：80 = 20*2 * 2
看起來是 x, y 分開做，然後折半枚舉
*/

int n, x, y, tmp;
vector<vector<int>> v(2);
vector<map<int, int>> s(2);
// v[0] = 橫向操作
// v[1] = 直向操作

void solve1(){

    // input
    cin >> n >> x >> y;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v[i%2].push_back(tmp);
    }

    // process
    int ans1=-1;
    int sz1=v[0].size()/2;
    int sz2=(v[0].size()+1)/2;
    for (int i=1 ; i<(1<<sz1) ; i+=2){
        int total=0;

        for (int j=0 ; j<sz1 ; j++){
            // 1=向右走，0=向左走
            if ((i>>j)&1) total+=v[0][j];
            else total-=v[0][j];
        }
        
        s[0][total]=i;
    }

    for (int i=0 ; i<(1<<sz2) ; i++){
        int total=y;

        for (int j=0 ; j<sz2 ; j++){
            // 1=向右走，0=向左走
            if ((i>>j)&1) total-=v[0][j+sz1];
            else total+=v[0][j+sz1];
        }

        if (s[0].find(total)!=s[0].end()){
            ans1=s[0][total]+(i<<sz1);
            break;
        }
    }

    int ans2=-1;
    int sz3=v[1].size()/2;
    int sz4=(v[1].size()+1)/2;
    for (int i=0 ; i<(1<<sz3) ; i++){
        int total=0;

        for (int j=0 ; j<sz3 ; j++){
            // 1=向右走，0=向左走
            if ((i>>j)&1) total+=v[1][j];
            else total-=v[1][j];
        }

        s[1][total]=i;
    }

    for (int i=0 ; i<(1<<sz4) ; i++){
        int total=x;

        for (int j=0 ; j<sz4 ; j++){
            // 1=向右走，0=向左走
            if ((i>>j)&1) total-=v[1][j+sz3];
            else total+=v[1][j+sz3];
        }

        if (s[1].find(total)!=s[1].end()){
            ans2=s[1][total]+(i<<sz3);
            break;
        }
    }

    string s1=bitset<30>(ans1).to_string();
    string s2=bitset<30>(ans2).to_string();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    s2='1'+s2;

    if (ans1==-1 || ans2==-1){
        cout << "No\n";
    }else{
        cout << "Yes\n";

        for (int i=0 ; i<n ; i++){
            if (i%2==0){
                if (s1[i/2]==s2[i/2]){
                    cout << 'L';
                }else{
                    cout << 'R';
                }
            }else{
                if (s2[(i+1)/2]==s1[i/2]){
                    cout << 'R';
                }else{
                    cout << 'L';
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