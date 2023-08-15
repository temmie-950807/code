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
const int MAX_N = 5e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
string s;
vector<string> v, add;
vector<char> green(5, '.'), yellow;

void solve1(){

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> s;
        v.push_back(s);
    }

    // 去重
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());

    // query
    for (int i=0 ; i<100 ; i++){
        assert(v.size());
        string c=v[rand()%v.size()];
        cout << c << "\n";
        cout.flush();
        cin >> s;

        bool flag=1;
        for (int j=0 ; j<5 ; j++){
            if (s[j]!='2'){ // 確認是否為正解
                flag=0;
            }

            if (s[j]=='2'){
                green[j]=c[j];

                // 如果這個字元曾經在 yellow 裡面，就直接刪去
                for (int k=0 ; k<yellow.size() ; k++){
                    if (yellow[k]==c[j]){
                        yellow.erase(yellow.begin()+k);
                        break;
                    }
                }

            }else if (s[j]=='1'){

                bool flag=1;
                for (int k=0 ; k<yellow.size() ; k++){
                    if (yellow[k]==c[j]){
                        flag=0;
                    }
                }

                if (flag){
                    yellow.push_back(c[j]);
                }

            }
        }

        if (flag==1){
            break;
        }

        // 篩選出下一回合所有可能的字串
        add.clear();
        for (auto x : v){
            bool flag=1;
            bitset<5> vis;

            for (int j=0 ; j<5 ; j++){
                if (green[j]=='.'){
                    // 檢查有沒有 yellow 裡面的東西
                    for (int k=0 ; k<yellow.size() ; k++){
                        if (x[j]==yellow[k]){
                            vis[k]=1;
                        }
                    }

                }else{
                    // 檢查是否符合 green 的規則
                    if (green[j]!=c[j]){
                        flag=0;
                    }
                }
            }

            if (vis.count()!=yellow.size()){
                flag=0;
            }

            if (flag){
                add.push_back(x);
            }
        }
        swap(v, add);
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