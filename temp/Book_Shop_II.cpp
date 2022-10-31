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

int n, x, tmp;
int dp[2][MAX_SIZE];
vector<int> tmp_wei(1), tmp_val(1), tmp_cnt(1);
vector<int> wei(1), val(1), cnt(1);

void solve(){
    // input
    cin >> n >> x;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        tmp_wei.push_back(tmp);
    }
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        tmp_val.push_back(tmp);
    }
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        tmp_cnt.push_back(tmp);
    }

    // init
    for (int i=1 ; i<=n ; i++){

        int k=1;
        while (tmp_cnt[i]>=k){
            wei.push_back(tmp_wei[i]);
            val.push_back(tmp_val[i]);
            cnt.push_back(k);

            tmp_cnt[i]-=k;
            k<<=1;
        }

        if (tmp_cnt[i]){
            wei.push_back(tmp_wei[i]);
            val.push_back(tmp_val[i]);
            cnt.push_back(tmp_cnt[i]);
        }
    }

    // debug(wei);
    // debug(val);
    // debug(cnt);
    // cout << endl;

    // DP
    for (int i=1 ; i<wei.size() ; i++){
        for (int j=0 ; j<=x ; j++){
            if (j-wei[i]*cnt[i]>=0){
                // 有可能選擇
                dp[i&1][j]=max(dp[!(i&1)][j], dp[!(i&1)][j-wei[i]*cnt[i]]+val[i]*cnt[i]);
            }else{
                // 不能選擇
                dp[i&1][j]=dp[!(i&1)][j];
            }
        }

        // for (int j=0 ; j<=x ; j++){
        //     cout << dp[i&1][j] << " ";
        // }   cout << endl;
    }

    // preview
    // for (int i=x-10 ; i<=x ; i++){
    //     cout << dp[0][i] << " ";
    // }   cout << endl;
    // for (int i=x-10 ; i<=x ; i++){
    //     cout << dp[1][i] << " ";
    // }   cout << endl;

    // output
    cout << dp[!(wei.size()&1)][x] << endl;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve();
    }
    return 0;
}