#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int INF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, q;
int op, i, j, v, d;
vector<set<pair<int, int>>> inv_G(MAX_SIZE);
vector<int> val(MAX_SIZE, MOD);
bitset<MAX_SIZE> vis;

// function
void dfs(int now){
    vector<pair<int, int>> rov;
    vis[now]=1;

    for (auto x : inv_G[now]){
        if (vis[x.first]==1){
            continue;
        }

        // cout << now << "->" << x.first << " need: " << x.second << endl;
        
        if (val[x.first]==MOD){
            // cout << x.first << " get val: " << val[now] << "-" << x.second << "=" << val[now]-val[x.second] << endl;
            val[x.first]=val[now]-x.second;
            rov.push_back(x);
            dfs(x.first);
        }
    }

    // remove
    for (auto x : rov){
        inv_G[now].erase(x);
        inv_G[x.first].erase({now, -x.second});
    }
}

void dis(int now, int f, int s){
    vis[now]=1;
    // cout << "now: " << now << " f: " << f << " s; " << s << endl;
    if (now==f){
        d=s;
        return;
    }

    for (auto x : inv_G[now]){
        if (vis[x.first]==1) continue;
        dis(x.first, f, s+x.second);
    }
}

void solve(){
    // input
    cin >> n >> q;
    for (int _=0 ; _<q ; _++){
        cin >> op;
        if (op==1){
            cin >> i >> j >> v;

            if (val[i]!=MOD && val[j]!=MOD && val[i]-val[j]!=v){
                // 兩個數字都有，且是不合法的
                cout << val[i]-val[j] << endl;

            }else if (val[i]!=MOD && val[j]!=MOD && val[i]-val[j]==v){
                // 兩個數字都有，且是合法的
                cout << v << endl;

            }else if (val[i]!=MOD && val[j]==MOD){
                // 只有val[i]
                val[j]=val[i]-v;
                cout << v << endl;

                // 用dfs更新數據
                vis=0;
                dfs(j);

            }else if (val[i]==MOD && val[j]!=MOD){
                // 只有val[j]
                val[i]=val[j]+v;
                cout << v << endl;

                // 用dfs更新數據
                vis=0;
                dfs(i);

            }else{
                auto it1=inv_G[i].lower_bound({j, -INF});
                auto it2=inv_G[j].lower_bound({i, -INF});

                if ((*it1).first==j && (*it1).second!=v){
                    // 兩個數字都沒有，且是不合法的
                    cout << (*it1).second << endl;

                }else if ((*it2).first==i && (*it2).second!=v){
                    // 兩個數字都沒有，且是不合法的
                    cout << (*it2).second << endl;
                
                }else{
                    // 兩個數字都沒有
                    vis=0;
                    dis(i, j, 0);

                    if (d==v || vis[j]==0){
                        // 合法
                        cout << v << endl;
                        inv_G[i].insert({j, v});
                        inv_G[j].insert({i, -v});

                    }else{
                        // 不合法
                        cout << d << endl;

                    }

                }
            }

        }else{
            cin >> i >> v;

            if (val[i]!=v && val[i]!=MOD){
                // 已經有這個數字了
                cout << val[i] << endl;

            }else{
                // 這裡還沒有數字
                val[i]=v;
                cout << v << endl;

                // 用dfs更新數據
                vis=0;
                dfs(i);
            }
        }

        // for (int i=1 ; i<=n ; i++){
        //     if (val[i]==MOD){
        //         cout << "X ";
        //     }else{
        //         cout << val[i] << " ";
        //     }
        // }
        // cout << endl << endl;
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