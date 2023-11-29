#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF=8e18+5;

int h, w, n;
int a, b;
vector<pair<int, int>> v;

int f(int now, int now_h, int now_w){
    if (now_h<=0 || now_w<=0) return now;
    if (now==n) return INF;
    int mi=INF;

    if (v[now].first>h){
        mi=min(mi, f(now+1, now_h, now_w-v[now].second));
    }
    if (v[now].first>w){
        mi=min(mi, f(now+1, now_h-v[now].second, now_w));
    }
    if (v[now].second>h){
        mi=min(mi, f(now+1, now_h, now_w-v[now].first));
    }
    if (v[now].second>w){
        mi=min(mi, f(now+1, now_h-v[now].first, now_w));
    }

    return mi;
}

void solve1(){

    // input
    cin >> h >> w >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());


    // process
    int a1=f(0, h, w);
    reverse(v.begin(), v.end());
    int a2=f(0, h, w);
    if (a1==INF && a2==INF){
        cout << -1 << "\n";
    }else{
        cout << min(a1, a2) << "\n";
    }
}


signed main(void){

    solve1();

    return 0;
}