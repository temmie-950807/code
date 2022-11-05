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

int n, q, tmp;
int a, b, c;
vector<int> v;

struct segment_tree{
    // [ll, rr)
    struct node{
        int sum;
    } seg[4*MAX_SIZE];

    int combine(int a, int b){
        return a+b;
    }

    void build(vector<int> *a, int idx, int ll, int rr){
        if (rr-ll==1){
            seg[idx].sum=(*a)[ll];
            return;
        }
        int mid=(ll+rr)/2;

        build(a, idx*2+1, ll, mid);
        build(a, idx*2+2, mid, rr);
        seg[idx].sum=combine(seg[2*idx+1].sum, seg[2*idx+2].sum);

    }

    void update(int pos, int idx, int ll, int rr, int val){
        if (rr-ll==1){
            seg[idx].sum=val;
            return;
        }
        int mid=(ll+rr)/2;
        if (pos<mid) update(pos, 2*idx+1, ll, mid, val);
        else update(pos, 2*idx+2, mid, rr, val);
        seg[idx].sum=combine(seg[2*idx+1].sum, seg[2*idx+2].sum);
        
    }

    int query(int idx, int ll, int rr, int ql, int qr){
        if (rr<=ql || qr<=ll) return 0;
        else if (ql<=ll && rr<=qr) return seg[idx].sum;
        else{
            int mid=ll+(rr-ll)/2;
            return combine(query(2*idx+1, ll, mid, ql, qr), query(2*idx+2, mid, rr, ql, qr));
        }
    }

} ST;

void solve(){
    // input
    cin >> n >> q;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // build
    ST.build(&v, 0, 0, n);


    // process
    for (int i=0 ; i<q ; i++){
        cin >> a >> b >> c;
        if (a==1){
            ST.update(i, 0, 0, n, c);
        }else{
            cout << ST.query(0, 0, n, b, c) << endl;
        }
    }

    // preview
    // int k=1, kk=0;
    // for (int i=0 ; i<15 ; i++){
    //     kk++;
    //     cout << setw(2) << ST.seg[i].sum << " ";
    //     if (kk==k){
    //         k<<=1;
    //         kk=0;
    //         cout << endl;
    //     }
    // }
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