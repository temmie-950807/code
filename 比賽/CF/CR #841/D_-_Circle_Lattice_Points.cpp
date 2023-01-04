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
const int MAX_SIZE = 1e5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int ans=0;
double x, y, r;
int tmp_x, tmp_y, tmp_r;
int ll, rr;
double uu, dd;

int get_value(int x){
    int ll=tmp_y, rr=tmp_y+tmp_r+1, mid, ans1=0, ans2=0;
    while (ll<rr){
        mid=ll+(rr-ll)/2;
        if ((tmp_x-x)*(tmp_x-x)+(tmp_y-mid)*(tmp_y-mid)<=tmp_r*tmp_r){
            ans1=mid;
            ll=mid+1;
        }else{
            rr=mid;
        }
    }

    ll=tmp_y-tmp_r, rr=tmp_y+1;
    while (ll<rr){
        mid=ll+(rr-ll)/2;
        if ((tmp_x-x)*(tmp_x-x)+(tmp_y-mid)*(tmp_y-mid)<=tmp_r*tmp_r){
            ans2=mid;
            rr=mid;
        }else{
            ll=mid+1;
        }
    }

    // cout << "ans1: " << ans1 << " ans2: " << ans2 << endl;
    return floor(ans1/10000.0)-ceil(ans2/10000.0)+1;
}

double sqrt(int num){
    double l=0, r=INF, mid;
    for (int i=0 ; i<150 ; i++){
        mid=(l+r)/2;
        if (mid*mid>=num){
            r=mid;
        }else{
            l=mid;
        }
    }
    return mid;
}

void solve(){
    // input
    cin >> x >> y >> r;
    tmp_x=x*10000;
    tmp_y=y*10000;
    tmp_r=r*10000;

    ll=ceil((tmp_x-tmp_r)/10000.0)*10000;
    rr=floor((tmp_x+tmp_r)/10000.0)*10000;

    // preview
    cout << "x: " << tmp_x << " y: " << tmp_y << " r: " << tmp_r << endl;
    cout << ll << " " << rr << endl;
    cout << "\n================\n\n";


    // get answer
    for (int i=ll ; i<=rr ; i+=10000){
        // sensor line
        ans+=get_value(i);
        cout << "i: " << i << " get: " << get_value(i);
    }

    // output
    cout << ans << endl;
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
