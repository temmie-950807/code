#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
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
const int MAX_SIZE = 2e5+5;
const int INF = 9e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, tmp;
int l, r, k;
vector<int> v(1);
vector<vector< pair<int, int> >> queries(MAX_SIZE); // <k, ans>
vector<int> ans(MAX_SIZE);
bitset<MAX_SIZE> vis;

// BIT
vector<int> BIT1(MAX_SIZE); // 計算個數
vector<int> BIT2(MAX_SIZE); // 計算總和
void update(int pos, int val1, int val2){
	for (int i=pos ; i<MAX_SIZE ; i+=i&-i){
		BIT1[i]+=val1;
		BIT2[i]+=val2;
	}
}

pair<int, int> query(int pos){
    if (pos==0){
        return {0, 0};
    }

	int ret1=0, ret2=0;
	for (int i=pos ; i>0 ; i-=i&-i){
		ret1+=BIT1[i];
		ret2+=BIT2[i];
	}
	return {ret1, ret2};
}

void solve1(){
    
    cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // qeuries
    for (int i=0 ; i<m ; i++){
        cin >> l >> r >> k;
        queries[l-1].push_back(make_pair(k, i));
        queries[r].push_back(make_pair(k, i));
    }

    // process
    for (int i=0 ; i<=n ; i++){
        if (i>=1){
            update(v[i], 1, v[i]);
        }

        for (auto x : queries[i]){
            if (vis[x.second]==0){
                vis[x.second]=1;
                
                pair<int, int> low, eql, hig;
                low=query(x.first-1);
                eql=query(x.first);
                hig=query(MAX_SIZE-1);

                ans[x.second]-=low.first*x.first;
                ans[x.second]-=hig.second-eql.second;

            }else{

                pair<int, int> low, eql, hig;
                low=query(x.first-1);
                eql=query(x.first);
                hig=query(MAX_SIZE-1);

                ans[x.second]+=low.first*x.first;
                ans[x.second]+=hig.second-eql.second;

            }
        }
    }

    // output
    for (int i=0 ; i<m ; i++){
        cout << ans[i]*2 << endl;
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