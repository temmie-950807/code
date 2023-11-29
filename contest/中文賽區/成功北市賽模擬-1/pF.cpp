#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

int n, l;
int a, b;
vector<pair<int, int>> v;
int x=0, y=0;

void solve2(){
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            a=v[i].first
        }
    }
}

void solve1(){
    
    // input
    cin >> n >> l;

    if (n<=2000){
        solve2();
        return;
    }

    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
        if (a<0) x++;
        else y++;
    }

    // process
    cout << x*(x-1)/2+y*(y-1)/2 << "\n";
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}