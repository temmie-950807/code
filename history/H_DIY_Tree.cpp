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
const int MAX_N = 50+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, k, tmp, mi=INF;
vector<int> d(MAX_N, INF);
vector<vector<int>> G(MAX_N, vector<int>(MAX_N));

struct disjoint_set{

    int n;
    vector<int> arr;

    disjoint_set(int _n=0){
        n=_n+5;
        arr.resize(n);
        for (int i=0 ; i<n ; i++){
            arr[i]=i;
        }
    };

    int find(int a){
        return arr[a]==a ? a : arr[a]=find(arr[a]);
    }

    void unite(int a, int b){
        arr[find(a)]=find(b);
    }

};

mt19937 seed(time(NULL));
int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(seed);
}

double drnd(double l, double r){
    return uniform_real_distribution<double>(l, r)(seed);
}

void solve1(){

    // init
    int now=0;
    vector<int> v(MAX_N), l(MAX_N), r(MAX_N);

    // 將生成樹設成中心為 n 的星狀圖
    for (int i=1 ; i<n ; i++){
        v[i]++;
        v[n]++;
        l[i]=i;
        r[i]=n;
        now+=G[i][n];
    }
    mi=min(mi, now);

    // 計算
    double temp=1e5;
    for (int _=0 ; _<100000 ; _++){
        
        // 選擇要刪除的邊
        int p=rnd(1, n-1);
        v[l[p]]--;
        v[r[p]]--;

        // 建目前的樹
        disjoint_set dsu(n);
        for (int i=1 ; i<n ; i++){
            if (i==p) continue;
            dsu.unite(l[i], r[i]);
        }

        // 隨機決定兩個合法的點建邊
        int x, y;
        do{
            x=rnd(1, n);
            y=rnd(1, n);
        } while (dsu.find(x)==dsu.find(y) || v[x]==d[x] || v[y]==d[y]);
        
        // 如果比較好或是一定機率將新的邊取代舊的邊
        int nxt=now-G[l[p]][r[p]]+G[x][y];
        if (nxt>now){
            cerr << temp << "\n";
            cerr << fixed << setprecision(10) << exp(1.0*(now-nxt)/temp) << "\n";
        }
        if (nxt<now || exp(1.0*(now-nxt)/temp)<=drnd(0, 1)){
            l[p]=x;
            r[p]=y;
            now=nxt;
        }

        // 建邊
        v[l[p]]++;
        v[r[p]]++;
        mi=min(mi, now);

        temp*=0.999;
    }
    dbg(temp);

    return;
}

signed main(void){
    fastio;

    // input
    cin >> n >> k;
    for (int i=1 ; i<=k ; i++){
        cin >> d[i];
    }
    for (int i=1 ; i<n ; i++){
        for (int j=i+1 ; j<=n ; j++){
            cin >> tmp;
            G[i][j]=tmp;
            G[j][i]=tmp;
        }
    }

    while (clock()<1*CLOCKS_PER_SEC){
        solve1();
    }

    // output
    cout << mi << "\n";

    return 0;
}