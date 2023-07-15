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
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, k, w;
int x, y;
int ip[3][130];
int arr[130][130];

void solve(){
    // input
    cin >> n >> m >> k >> w;
    for (int i=0 ; i<k ; i++){
        cin >> ip[0][i] >> ip[1][i] >> ip[2][i];
    }
    for (int i=0 ; i<w ; i++){
        cin >> x >> y;
        arr[x][y]=2;
    }

    // process
    for (int i=0 ; i<k ; i++){
        if (arr[ip[0][i]][ip[1][i]]==2){
            continue;
        }else if (ip[2][i]==1){
            x=ip[0][i];
            y=ip[1][i];

            arr[x][y]=1;
            while (x<n && arr[x+1][y]!=2){
                arr[++x][y]=1;
            }

            x=ip[0][i];
            y=ip[1][i];

            while (x>1 && arr[x-1][y]!=2){
                arr[--x][y]=1;
            }
        }else if (ip[2][i]==2){
            x=ip[0][i];
            y=ip[1][i];

            arr[x][y]=1;
            while (y<m && arr[x][y+1]!=2){
                arr[x][++y]=1;
            }

            x=ip[0][i];
            y=ip[1][i];

            while (y>1 && arr[x][y-1]!=2){
                arr[x][--y]=1;
            }
        }
    }

    // preview
    // debug(arr, n+2, m+2);

    // output
    int s=0;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            if (arr[i][j]==1) s++;
        }
    }
    cout << s << endl;
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}