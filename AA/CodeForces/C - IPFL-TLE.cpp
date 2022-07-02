// 23 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

struct Data{
    int t;
    int a;
    int b;
};


signed main(void){
	fastio;
	
    int n, q, t, a, b;
    int cnt=0;
    string s;
    Data d;
    vector<Data> v;

    cin >> n >> s >> q;
    for (int i=0 ; i<q ; i++){
        cin >> d.t >> d.a >> d.b;
        d.a--;
        d.b--;

        if (d.t==1){
            if (cnt%2==1){
                v.push_back({2, 0, 0});
            }
            cnt=0;
            v.push_back(d);
        }else{
            cnt++;
        }
    }
    if (cnt%2==1){
        v.push_back({2, 0, 0});
    }

    for (int i=0 ; i<v.size() ; i++){
        t = v[i].t;
        a = v[i].a;
        b = v[i].b;

        if (t==1){
            s[a]^=s[b];
            s[b]^=s[a];
            s[a]^=s[b];
        }else{
            for (int i=0 ; i<n ; i++){
                s[i]^=s[n+i];
                s[n+i]^=s[i];
                s[i]^=s[n+i];
            }
        }
    }

    cout << s << "\n";
    return 0;
}