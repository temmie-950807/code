#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 10000;
const double EPS = 1e-6;

struct matrix{
    int n, m;
    vector<vector<int>> arr;
    
    matrix(int _n=1, int _m=1){
        n=_n;
        m=_m;
        arr.resize(n, vector<int>(m, 0));
    }

    matrix operator * (matrix B){
        matrix ret;
        for (int i=0 ; n<n ; i++){
            for (int j=0 ; j<B.m ; j++){
                ret.arr[i][j]=0;
                for (int k=0 ; k<m ; k++){
                    ret.arr[i][j]+=arr[i][k]*B.arr[k][j];
                }
                ret.arr[i][j]%=MOD;
            }
        }
        return ret;
    }

    void print(){
        debug(arr, n, m);
    }
};

int n, s;
vector<vector<int>> v;

vector<string> pos; // base matrix
vector<pair<string, string>> pos_2; // transform matrix

const int mx[4]={-2, -1, -1, -2};
const int my[4]={1, 2, -2, -1};

void dfs(vector<vector<int>> v, int cnt){
    if (cnt>n+1){
        s++;

        string A, B, C;
        for (int i=0 ; i<6 ; i++){
            A+=v[cnt-2][i]+'0';
            B+=v[cnt-1][i]+'0';
            C+=v[cnt-0][i]+'0';
        }
        cout << "A: " << A << " B: " << B << " C: " << C << endl;
        // cout << v.size() << endl;
        for (int i=0 ; i<6 ; i++){
            for (int j=0 ; j<n+3 ; j++){
                cout << v[j][i] << " ";
            }   cout << endl;
        }       cout << endl;
        return;
    }
    else v.push_back({1, 1, 1, 1, 1, 1});

    for (int i=0 ; i<6 ; i++){
        for (int j=i+1 ; j<6 ; j++){
            // init
            bool check=1;
            fill(v[cnt+1].begin(), v[cnt+1].end(), 1);
            v[cnt+1][i]=0;
            v[cnt+1][j]=0;

            for (int k=0 ; k<4 ; k++){
                if (i+my[k]<0 || i+my[k]>5) continue;
                check*=v[cnt+1+mx[k]][i+my[k]];
            }
            for (int k=0 ; k<4 ; k++){
                if (j+my[k]<0 || j+my[k]>5) continue;
                check*=v[cnt+1+mx[k]][j+my[k]];
            }

            // next
            if (check) dfs(v, cnt+1);
        }
    }
}

void solve1(){
    // init
    s=0;
    v.clear();
    v.push_back({1, 1, 1, 1, 1, 1});
    v.push_back({1, 1, 1, 1, 1, 1});

    // input
    cin >> n;

    // enumerate
    dfs(v, 1);

    // output
    cout << s << endl;
    return;
}

void solve2(){
    cin >> n;

    while (n){
        
        if (n&1){
            
        }

        n>>=1;
    }
    
}

signed main(void){
    fastio;

    // init
    for (int i=0 ; i<6 ; i++){
        for (int j=i+1 ; j<6 ; j++){
            // init
            vector<int> v(6, 1);
            string s;
            bool check=1;
            v[i]=0;
            v[j]=0;

            for (int k=0 ; k<6 ; k++){
                s+=v[k]+'0';
            }

            pos.push_back(s);
        }
    }
    sort(pos.begin(), pos.end());
    for (auto x : pos){
        cout << x << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    for (auto x : pos){
        for (auto y : pos){
            pos_2.push_back({x, y});
        }
    }

    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}