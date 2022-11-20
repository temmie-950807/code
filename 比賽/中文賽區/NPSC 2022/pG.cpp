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

int n, m, tmp;
vector<int> a(1), b(1);
int dp[1005][1005], ma[1005][1005];

void solve(){
    // input
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i=0 ; i<m ; i++){
        cin >> tmp;
        b.push_back(tmp);
    }

    // process - DP
    for (int i=1 ; i<=n ; i++){
        if (dp[i-1][0]+a[i]<0){
            dp[i][0]=-INF;
            ma[i][0]=-INF;
        }else{
            dp[i][0]=dp[i-1][0]+a[i];
            ma[i][0]=max(ma[i-1][0], dp[i][0]);
        }
    }
    for (int j=1 ; j<=m ; j++){
        if (dp[0][j-1]+b[j]<0){
            dp[0][j]=-INF;
            ma[0][j]=-INF;
        }else{
            dp[0][j]=dp[0][j-1]+b[j];
            ma[0][j]=max(ma[0][j-1], dp[0][j]);
        }
    }

    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            if (dp[i-1][j]+a[i]<0 && dp[i][j-1]+b[j]<0){
                dp[i][j]=-INF;
                ma[i][j]=-INF;

            }else if (dp[i-1][j]+a[i]<0){
                dp[i][j]=dp[i][j-1]+b[j];
                ma[i][j]=max(ma[i][j-1], dp[i][j]);
                if (dp[i][j]<0){
                    dp[i][j]=-INF;
                    ma[i][j]=-INF;
                }

            }else if (dp[i][j-1]+b[j]<0){
                dp[i][j]=dp[i-1][j]+a[i];
                ma[i][j]=max(ma[i-1][j], dp[i][j]);
                if (dp[i][j]<0){
                    dp[i][j]=-INF;
                    ma[i][j]=-INF;
                }

            }else {
                if (max(ma[i-1][j], dp[i-1][j]+a[i])<=max(ma[i][j-1], dp[i][j-1]+b[j])){
                    dp[i][j]=dp[i-1][j]+a[i];
                    ma[i][j]=max(ma[i-1][j], dp[i][j]);
                    if (dp[i][j]<0){
                        dp[i][j]=-INF;
                        ma[i][j]=-INF;
                    }
                }else{
                    dp[i][j]=dp[i][j-1]+b[j];
                    ma[i][j]=max(ma[i][j-1], dp[i][j]);
                    if (dp[i][j]<0){
                        dp[i][j]=-INF;
                        ma[i][j]=-INF;
                    }
                }
            }
        }
    }

    if (ma[n][m]==-INF){
        cout << -1 << endl;
    }else{
        cout << ma[n][m] << endl;
    }
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
