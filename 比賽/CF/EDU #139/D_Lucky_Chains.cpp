#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define int long long
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

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
const int INF = 1e9;

int n, a, b;
vector<int> prime, is_prime(3200);

// function
void get_prime(){
    for (int i=2 ; i<3200 ; i++){
        if (!is_prime[i]){
            prime.push_back(i);
            for (int j=i ; j<3200 ; j+=i){
                if (!is_prime[j]) is_prime[j]=i;
            }
        }
    }
}

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

void solve1(){
    // input
    a=nextint();
    b=nextint();

    // check 1
    for (int i=0 ; i<10 ; i++){
        if (__gcd(a+i, b+i)!=1){
            cout << i << endl;
            return;
        }
    }

    // check 2
    int kk=b-a, mi=INF;

    for (auto x : prime){
        if (x>kk || kk==1) break;
        if (kk%x==0){
            mi=min(mi, (a/x+1)*x-a);
        }
        while (kk%x==0) kk/=x;
    }
    if (kk!=1){
        mi=min(mi, (a/kk+1)*kk-a);
    }

    if (mi==INF){
        cout << -1 << endl;
    }else{
        cout << mi << endl;
    }

    return;
}

void solve2(){

    int a, b;

    cin >> a >> b;
    for (int i=0 ; i<500000 ; i++){
        if (__gcd(a+i, b+i)!=1){
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

signed main(void){
    fastio;

    get_prime();
    
    int t=1;
    t=nextint();
    while (t--){
        solve1();
    }
    return 0;
}