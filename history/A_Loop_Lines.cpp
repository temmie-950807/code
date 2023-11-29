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
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

// 下, 右, 上, 左
const int mx[4]={1, 0, -1, 0};
const int my[4]={0, 1, 0, -1};

const int pp[8][4]={
    {-1, -1, 3, 2},
    {3, -1, -1, 0},
    {1, 0, -1, -1},
    {-1, 2, 1, -1},
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {-1, 3, -1, 1},
    {2, -1, 0, -1},
};

gp_hash_table<int, int, custom_hash>;

vector<string> ss(30);
int temp, max_score, now_score, nxt_socre;
vector<string> ans_dir(30, string(30, '0')), now_dir(30, string(30, '0'));

mt19937 seed(time(NULL));
int rnd(int l, int r){return uniform_int_distribution<int>(l, r)(seed);}

bool in(int x, int y){
    return 0<=x && x<30 && 0<=y && y<30;
}

int score(vector<string> &dir){
    int ma1=0, ma2=0;

    int counter=1;
    vector<bitset<30>> vis(30);
    for (int i=0 ; i<30 ; i++){
        for (int j=0 ; j<30 ; j++){
            if (vis[i][j]==0){
                vis[i][j]=counter;
                for (int k=0 ; k<4 ; k++){
                    int nx=i;
                    int ny=j;
                    int nd=k;
                    int ans=0;
                    bool flag=1;

                    while (1){
                        if (i==3 && j==17){
                            dbg(nx, ny);
                        }

                        int d2=pp[ss[nx][ny]-'0'][nd];
                        if (d2==-1){
                            flag=0;
                            break;
                        }
                        nx+=mx[d2];
                        ny+=my[d2];
                        if (!in(nx, ny)){
                            flag=0;
                            break;
                        }

                        vis[nx][ny]=counter;
                        nd=(d2+2)%4;
                        if (nx==i && ny==j){
                            break;
                        }
                    }

                    if (flag){
                        if (ans>ma1){
                            ma2=ma1;
                            ma1=ans;
                        }else if (ans>ma2){
                            ma2=ans;
                        }
                    }
                    
                }
                counter++;
            }

        }
    }

    return ma1*ma2;
}

mt19937 seed(time(NULL));
int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(seed);
}

double drnd(double l, double r){
    return uniform_real_distribution<double>(l, r)(seed);
}

void solve1(){

    // input
    for (int i=0 ; i<30 ; i++){
        cin >> ss[i];
    }

    // process
    max_score=score(now_dir);
    dbg(max_score);

    while (clock()<0.9*CLOCKS_PER_SEC){
        
        // 改其中一個格子
        int ix=rnd(0, 29);
        int iy=rnd(0, 29);
        int now_val=now_dir[ix][iy];
        int nxt_val;
        do{
            nxt_val=rnd('0', '3');
        } while (nxt_val==now_val);
        now_dir[ix][iy]=nxt_val;

        // 計算差值
        nxt_socre=score(now_dir);

        if (nxt_socre>max_score){
            max_score=nxt_socre;
            ans_dir=now_dir;
        }

        // 確認更動
        if (nxt_socre>now_score || drnd(0, 1)<=exp((nxt_socre-now_score)/temp)){
            now_score=nxt_socre;
        }else{
            now_dir[ix][iy]=now_val;
        }

        // 改溫度
        temp*=0.999;
    }
    
    // output
    for (int i=0 ; i<30 ; i++){
        cout << ans_dir[i];
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