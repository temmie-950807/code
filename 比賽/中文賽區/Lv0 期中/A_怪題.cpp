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

int n, tmp;
string s="34ccmhq890hf32809crjqfjq928ux89023uxcmtu849qc567q64892c17944018c7124m87cm04017cm4098x7mx71x41jxy90cyc4tg140c74yc91842cm138c4cxy1xmh13890xy4m340rh9038yr98cjf390cm2hcflwcf7gla8wyr78nlyrcm8oymtco4378cfhjilaa23akhc1ak2u41u845chatmgc2thsukmcc78a2k73y5c3a7ytk8k25mya7k5ya852ya78k25ya2578ya2m5ka257yccmy378akcy5mak3y57aky783cm785m3y785ckanmcy572c85amk32yc3mky57a8k35cm2y578cmy2k52c7y23k5c78y3cirhmh3kcrca02cl3ty8a2x34u10x9374x0";
vector<int> v;

void solve(){
    // input
    cin >> tmp;

    // process
    int cnt=0;
    for (int i=0 ; i<s.size() ; i++){
        if (s[i]>='0' && s[i]<='9') cnt++;

        if (cnt==tmp){
            cout << s[i] << endl;
            return;
        }
    }

    // output
    cout << -1 << endl;
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}