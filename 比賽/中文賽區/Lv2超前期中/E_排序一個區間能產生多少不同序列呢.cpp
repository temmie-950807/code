#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
const int MAX_SIZE = 5e3+5;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
vector<int> v, k;
set<vector<int>> s;
int dp[MAX_SIZE][MAX_SIZE];

// function
int ST[13][MAX_SIZE];
void build(){
    int h=floor(__lg(n));

    for (int j=0 ; j<n ; j++){
        ST[0][j]=v[j];
    }

    for (int i=1 ; i<=h ; i++){
        for (int j=0 ; j+(1<<i)<=n ; j++){
            ST[i][j]=min(ST[i-1][j], ST[i-1][j+(1<<(i-1))]);
        }
    }

    return;
}
int query(int ll, int rr){
    int p=31-__builtin_clz(rr-ll);
    return min(ST[p][ll], ST[p][rr-(1<<p)]);
}


// solution
void solve1(){
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // numerate (n^2)
    for (int i=0 ; i<n ; i++){
        for (int j=i ; j<n ; j++){
            k=v;
            sort(k.begin()+i, k.begin()+j+1);
            s.insert(k);
        }
    }

    // output
    cout << s.size() << endl;
    return;
}

void solve2(){
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    build();

    // dp
    for (int i=0 ; i<n ; i++){
        dp[i][i]=1;
    }
    for (int r=0 ; r<n ; r++){
        for (int l=r ; l>=0 ; l--){
            if (l==r) continue;

            cout << endl;
            cout << "res of l+1: " << query(l+1, r+1) << " res of r-1: " << query(l, r) << endl;
            cout << "l: " << l << " r: " << r << " | ";

            if (r-l==1){
                if (query(l+1, r+1)!=v[l]){
                    cout << "B" << endl;
                    dp[l][r]=dp[l+1][r]+1;
                }else if (query(l, r)!=v[r]){
                    cout << "C" << endl;
                    dp[l][r]=dp[l][r-1]+1;
                }else{
                    cout << "D" << endl;
                    dp[l][r]=dp[l+1][r];
                }
            }else{
                if (query(l+1, r+1)!=v[l] && query(l, r)!=v[r]){
                    cout << "A" << endl;
                    dp[l][r]=max(dp[l+1][r], dp[l][r-1])+1;
                }else if (query(l+1, r+1)!=v[l]){
                    cout << "B" << endl;
                    dp[l][r]=dp[l+1][r]+1;
                }else if (query(l, r)!=v[r]){
                    cout << "C" << endl;
                    dp[l][r]=dp[l][r-1]+1;
                }else{
                    cout << "D" << endl;
                    dp[l][r]=dp[l+1][r];
                }
            }
        }
    }

    debug(dp, n, n);
    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        // solve1();
        solve2();
    }
    return 0;
}