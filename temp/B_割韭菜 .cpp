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

// fast IO
inline char readchar(){
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}
inline int nextint(){
    int x = 0, c = readchar(), neg = false;
    while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
    if(c == '-') neg = true, c = readchar();
    while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
    if(neg) x = -x;
    return x; // returns 0 if EOF
}

// declare
const int MAX_SIZE = 1500+5;
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, m, tmp;
int ma=-INF, ax, ay, bx, by;
vector<int> v;
int arr[MAX_SIZE][MAX_SIZE];


void find_max_range_1(int y){
    int s=0, cma=-INF, cx0, cx1, cx2;
    int dma=-INF, dx;
    int check=0;

    for (int i=1 ; i<=m ; i++){
        if (arr[y][i]>dma){
            dma=arr[y][i];
            dx=i;
        }

        if (s+arr[y][i]>0){
            if (check==0){
                check=1;
                cx0=i;
            }

            s+=arr[y][i];
            if (s>cma){
                cma=s;
                cx1=cx0;
                cx2=i;
            }
        }else{
            check=0;
            s=0;
        }
    }

    if (dma<0){
        // 只選一個東西比較好
        if (dma>ma){
            ma=dma;
            ax=dx;
            ay=y;
            bx=dx;
            by=y;
        }
    }else{
        // 可以選多一點東西
        if (cma>ma){
            ma=cma;
            ax=cx1;
            ay=y;
            bx=cx2;
            by=y;
        }
    }
}

void find_max_range_2(int x){
    int s=0, cma=-INF, cy0, cy1, cy2; // range sum
    int dma=-INF, dy; // single value sum
    int check=0;

    for (int i=1 ; i<=n ; i++){
        if (arr[i][x]>dma){
            dma=arr[i][x];
            dy=i;
        }

        if (s+arr[i][x]>0){
            if (check==0){
                check=1;
                cy0=i;
            }

            s+=arr[i][x];
            if (s>cma){
                cma=s;
                cy1=cy0;
                cy2=i;
            }
        }else{
            check=0;
            s=0;
        }
    }

    if (dma<0){
        // 只選一個東西比較好
        if (dma>ma){
            ma=dma;
            ax=x;
            ay=dy;
            bx=x;
            by=dy;
        }
    }else{
        // 可以選多一點東西
        if (cma>ma){
            ma=cma;
            ax=x;
            ay=cy1;
            bx=x;
            by=cy2;
        }
    }
}


void solve(){
    n=nextint();
    m=nextint();
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            tmp=nextint();
            arr[i][j]=tmp;
        }
    }

    for (int i=1 ; i<=n ; i++){
        find_max_range_1(i);
    }
    for (int i=1 ; i<=m ; i++){
        find_max_range_2(i);
    }

    // cout << ma << " " << ax << " " << ay << " " << bx << " " << by << endl;
    cout << ma << endl;
    for (int i=1 ; i<ax ; i++) cout << "L";
    for (int i=m ; i>bx ; i--) cout << "R";
    for (int i=1 ; i<ay ; i++) cout << "U";
    for (int i=n ; i>by ; i--) cout << "D";

    if (ax==bx) cout << "R";
    else cout << "U";
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