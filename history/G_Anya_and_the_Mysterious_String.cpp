#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

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

int n, q, tmp;
int cmd, l, r, x;
string s;
set<int> bad2, bad3; // 存 i 開始算起 2, 3 個字元能不能構成迴文
vector<int> v, BIT; // v 存字母順序 a->0, z->25 | BIT 用差分區間修改單點查詢 存每個點加上的值

// 只要一個字串有 aba 或是 aa 就不是 beautiful 的

void update(int pos, int val){
    for (int i=pos ; i<BIT.size() ; i+=i&-i) BIT[i]=(BIT[i]+val)%26;
}

int query(int pos){
    if (pos<=0) return 0;

    int ret=0;
    for (int i=pos ; i>0 ; i-=i&-i) ret=(ret+BIT[i])%26;
    return ret;
}

void init(){
    bad2.clear();
    bad3.clear();
    v.clear();
    BIT.clear();

    v.resize(n+5, -1);
    BIT.resize(n+5);

    for (int i=0 ; i<n ; i++){
        v[i+1]=s[i]-'a';
    }
    for (int i=1 ; i<=n ; i++){
        if (i+1<=n && v[i]==v[i+1]) bad2.insert(i);
        if (i+2<=n && v[i]==v[i+2]) bad3.insert(i);
    }
}

void print(){
    for (int i=1 ; i<=n ; i++){
        cerr << (char)((v[i]+query(i))%26+'a');
    }
    cerr << "\n";
    cerr << "bad2: ";
    debug(bad2);
    cerr << "bad3: ";
    debug(bad3);
    cerr << "\n";
}

void modify(int pos){
    // 只更新 l, r 附近 5 個位置有沒有改變
    for (int i=max(1LL, pos-5) ; i<=min(n, pos+5) ; i++){
        if (i+1<=n){
            if ((v[i]+query(i))%26==(v[i+1]+query(i+1))%26) bad2.insert(i);
            else bad2.erase(i);
        }
        if (i+2<=n){
            if ((v[i]+query(i))%26==(v[i+2]+query(i+2))%26) bad3.insert(i);
            else bad3.erase(i);
        }
    }
}

void solve1(){

    // input
    cin >> n >> q;
    cin >> s;

    init();
    
    // queries
    for (int i=0 ; i<q ; i++){
        cin >> cmd;

        if (cmd==1){
            cin >> l >> r >> x;
            x%=26;
            update(l, x);
            update(r+1, 26-x);
            modify(l);
            modify(r);

        }else{
            cin >> l >> r;

            bool flag=0; // 有沒有迴文
            if (r-l+1>=2){
                auto it=bad2.lower_bound(l);
                if (it!=bad2.end() && *it<=r-1) flag=1; // 找 [l, r-1] 開始, 長度為 2 的迴文
            }
            if (r-l+1>=3){
                auto it=bad3.lower_bound(l);
                if (it!=bad3.end() && *it<=r-2) flag=1; // 找 [l, r-2] 開始, 長度為 3 的迴文
            }

            cout << (flag ? "NO" : "YES") << "\n";
        }
    }
    
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }
    return 0;
}