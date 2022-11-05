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

struct node{
    int a=1, b=0;
    int c=0, d=1;
} tmp;
int r, n, m;
int ll, rr;
vector<node> v;


struct segment_tree{
    // [ll, rr)
    node seg[2][4*MAX_SIZE];

    node combine(node x, node y){
        node ret;
        ret.a=(x.a*y.a + x.c*y.b)%r;
        ret.b=(x.b*y.a + x.d*y.b)%r;
        ret.c=(x.a*y.c + x.c*y.d)%r;
        ret.d=(x.b*y.c + x.d*y.d)%r;
        return ret;
    }

    void build(vector<node> *a, int idx, int ll, int rr){
        if (rr-ll==1){
            seg[0][idx]=(*a)[ll];
            seg[1][idx]=(*a)[ll];
            return;
        }
        int mid=(ll+rr)/2;

        build(a, idx*2+1, ll, mid);
        build(a, idx*2+2, mid, rr);
        
        if ((mid+1)%2==0){
            cout << "AA" << endl;
            seg[0][idx]=combine(seg[0][2*idx+1], seg[0][2*idx+2]);
            seg[1][idx]=combine(seg[1][2*idx+2], seg[0][2*idx+1]);
        }else{
            cout << "BB" << endl;
            seg[0][idx]=combine(seg[0][2*idx+2], seg[1][2*idx+1]);
            seg[1][idx]=combine(seg[1][2*idx+1], seg[1][2*idx+2]);
        }
    }

    node query(int idx, int ll, int rr, int ql, int qr){
        cout << "ll: " << ll << " rr: " << rr << endl;
        if (rr<=ql || qr<=ll) return node();
        else if (ql<=ll && rr<=qr){
            return seg[(rr+ql+1)%2][idx];
        }else{
            int mid=ll+(rr-ll)/2;

            if ((mid-1)%2==0){
                if ((rr+ql+1)%2==0){
                    cout << "A" << endl;
                    return combine(seg[0][2*idx+1], seg[0][2*idx+2]);
                }else{
                    cout << "B" << endl;
                    return combine(seg[1][2*idx+2], seg[0][2*idx+1]);
                }
            }else{
                if ((rr+ql+1)%2==0){
                    cout << "C" << endl;
                    return combine(seg[0][2*idx+2], seg[1][2*idx+1]);
                }else{
                    cout << "D" << endl;
                    return combine(seg[1][2*idx+1], seg[1][2*idx+2]);
                }
            }
        }
    }
} ST;

void print(node tmp){
    cout << tmp.a << " " << tmp.b << endl << tmp.c << " " << tmp.d << endl << endl;
}

void solve(){
    // input
    cin >> r >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp.a >> tmp.b >> tmp.c >> tmp.d;
        v.push_back(tmp);
    }

    // build
    ST.build(&v, 0, 0, n);

    // query
    for (int i=0 ; i<m ; i++){
        cin >> ll >> rr;
        print(ST.query(0, 0, n, ll-1, rr));
    }

    // preview
    for (int i=1 ; i<4 ; i++){
        for (int j=(1<<(i-1)) ; j<(1<<i) ; j++){
            cout << ST.seg[0][j-1].a << " " << ST.seg[0][j-1].b << " | ";
        }
        cout << endl;
        for (int j=(1<<(i-1)) ; j<(1<<i) ; j++){
            cout << ST.seg[0][j-1].c << " " << ST.seg[0][j-1].d << " | ";
        }
        cout << endl;
        cout << endl;
    }

    cout << "=====================" << endl;

    for (int i=1 ; i<4 ; i++){
        for (int j=(1<<(i-1)) ; j<(1<<i) ; j++){
            cout << ST.seg[1][j-1].a << " " << ST.seg[1][j-1].b << " | ";
        }
        cout << endl;
        for (int j=(1<<(i-1)) ; j<(1<<i) ; j++){
            cout << ST.seg[1][j-1].c << " " << ST.seg[1][j-1].d << " | ";
        }
        cout << endl;
        cout << endl;
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