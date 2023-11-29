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

int n;
string r, c;
char A[3]={'A', 'B', 'C'};
vector<vector<bool>> r_cnt, c_cnt;
vector<string> arr;

bool dfs(int now_x, int now_y){

    if (now_x==n){
        // check
        bool flag=1;
        for (int i=0 ; i<3 ; i++){
            for (int j=0 ; j<n ; j++){
                flag&=r_cnt[i][j];
                flag&=c_cnt[i][j];
            }
        }

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (arr[i][j]!='.'){
                    flag&=(arr[i][j]==r[i]);
                    break;
                }
            }
        }

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (arr[j][i]!='.'){
                    flag&=(arr[j][i]==c[i]);
                    break;
                }
            }
        }

        // for (auto x : arr){
        //     cerr << x << "\n";
        // }
        // cerr << "\n";

        return flag;

    }else{
        int cnt1=0, cnt2=0;
        for (int i=0 ; i<3 ; i++){
            cnt1+=r_cnt[i][now_x];
        }
        for (int i=0 ; i<3 ; i++){
            cnt2+=c_cnt[i][now_y];
        }

        for (int i=0 ; i<3 ; i++){
            if (r_cnt[i][now_x]==0 && c_cnt[i][now_y]==0){

                if (cnt1==0 && A[i]!=r[now_x]) continue;
                if (cnt2==0 && A[i]!=c[now_y]) continue;

                r_cnt[i][now_x]=1;
                c_cnt[i][now_y]=1;
                arr[now_x][now_y]=A[i];

                if (dfs(now_x+(now_y+1==n), (now_y+1)%n)) return true;

                r_cnt[i][now_x]=0;
                c_cnt[i][now_y]=0;
                arr[now_x][now_y]='.';
            }
        }

        if (dfs(now_x+(now_y+1==n), (now_y+1)%n)) return true;
        return false;
    }
}

void solve1(){

    // input
    cin >> n;
    cin >> r;
    cin >> c;

    // init
    r_cnt.resize(3, vector<bool>(n));
    c_cnt.resize(3, vector<bool>(n));
    arr.resize(n, string(n, '.'));

    // process
    if (dfs(0, 0)){
        cout << "Yes\n";
        for (auto x : arr){
            cout << x << "\n";
        }
    }else{
        cout << "No\n";
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