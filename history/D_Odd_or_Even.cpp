#include <bits/stdc++.h>
using namespace std;

template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);

int n, k;
vector<vector<int>> v(2);
vector<int> group(1005), ans(1005);
bool now=0, pre=0;

int main(){

    // input
    cin >> n >> k;

    // 取得 k~n 的資訊
    for (int i=k ; i<=n ; i++){
        cout << "? ";
        for (int j=1 ; j<=k-1 ; j++) cout << j << " ";
        cout << i;
        cout << "\n";
        cout.flush();

        cin >> now;
        group[i]=group[i-1]^(now!=pre);
        v[group[i]].push_back(i);
        pre=now;
    }

    // 取得 1~k-1 的資訊
    for (int i=k-1 ; i>=1 ; i--){
        cout << "? ";
        for (int j=1 ; j<i ; j++) cout << j << " ";
        for (int j=n-(k-i) ; j<=n ; j++) cout << j << " ";
        cout << "\n";
        cout.flush();

        cin >> now;
        group[i]=group[n-(k-i)]^(now!=pre);
        v[group[i]].push_back(i);
        pre=now;
    }

    // get answer
    int p=0;
    for (auto x : v[0]){
        ans[x]=1;
    }
    for (int i=n-k+1 ; i<=n ; i++){
        p^=ans[i];
    }

    // output
    cout << "! ";
    for (int i=1 ; i<=n ; i++) cout << (ans[i]^(pre!=p)) << " ";
    cout << "\n";
    cout.flush();
}