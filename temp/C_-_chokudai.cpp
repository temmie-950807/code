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
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
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
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
// ===================================

// declare
int cnt, ans;
string tmp, s;
const char cc[8]={'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
vector<int> dp(MAX_SIZE);

void solve(){
    // input
    cin >> tmp;
    for (int i=0 ; i<tmp.size() ; i++){
        for (int j=0 ; j<8 ; j++){
            if (tmp[i]==cc[j]){
                s+=tmp[i];
            }
        }
    }

    // dp
    for (int j=0 ; j<s.size() ; j++){
        if (s[j]==cc[0]){
            dp[j]=1;
        }
    }

    debug(dp, s.size());

    for (int i=1 ; i<8 ; i++){
        cnt=0;
        for (int j=0 ; j<s.size() ; j++){
            if (s[j]==cc[i-1]){
                cnt+=dp[j];
                if (cnt>=MOD) cnt-=MOD;
                dp[j]=0;
            }
            if (s[j]==cc[i]){
                dp[j]=cnt;
            }

        }

        debug(dp, s.size());
    }

    // preview
    // cout << s << endl;

    // output
    ans=0;
    for (int j=0 ; j<s.size() ; j++){
        ans+=dp[j];
        if (ans>=MOD) ans-=MOD;
    }
    cout << ans;
}

signed main(void){
    fastio;
    
    int aa=13;
    string bb="abc";
    double cc=69.420;
    cout << endl;

    int t=1;
    while (t--){
        solve();
    }
    return 0;
}