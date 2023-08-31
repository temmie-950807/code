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
bool debug_mode=false;
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
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m;
int sx, sy;
int gx, gy;
vector<string> v;

char cc[5]={'>', '<', '^', 'v', '#'};
int mx[4]={0, 0, -1, 1};
int my[4]={1, -1, 0, 0};

bool in(int x, int y){
    return 0<=x && x<n && 0<=y && y<m;
}

int is_blocker(int x, int y){
    int op=-1;
    for (int i=0 ; i<5 ; i++){
        if (v[x][y]==cc[i]){
            op=i;
        }
    }
    return op;
}

void fill(int x, int y){
    int op=is_blocker(x, y);
    if (op==-1 || op==4) return;

    v[x][y]='#';
    while (in(x+mx[op], y+my[op]) && is_blocker(x+mx[op], y+my[op])==-1){
        x+=mx[op];
        y+=my[op];
        v[x][y]='@';
    }
}

void solve1(){

    // input
    cin >> n >> m;
    v.resize(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    // init
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (v[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if (v[i][j]=='G'){
                gx=i;
                gy=j;
            }
        }
    }
    
    // mark all sight
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            fill(i, j);
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (v[i][j]=='@') v[i][j]='#';
        }
    }

    // preview
    for (auto x : v){
        cerr << x << "\n";
    }

    // find minimum path
    queue<tuple<int, int, int>> qq;
    qq.push({sx, sy, 0});
    while (qq.size()){
        int x, y, len;
        tie(x, y, len)=qq.front();
        qq.pop();

        if (x==gx && y==gy){
            cout << len << "\n";
            return;
        }

        for (int i=0 ; i<4 ; i++){
            if (in(x+mx[i], y+my[i]) && is_blocker(x+mx[i], y+my[i])==-1){
                v[x+mx[i]][y+my[i]]='#';
                qq.push({x+mx[i], y+my[i], len+1});
            }
        }
    }

    // output
    cout << -1 << "\n";
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