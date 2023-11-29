#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=5e5+5;
const int INF=2e18;

int n, k, p, tmp;
vector<int> v;

void solve1(){

    // input
    cin >> n >> k >> p;

    int total=0;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        total+=tmp;
        v.push_back(tmp);
    }

    // output
    cout << total << "\n";
}

signed main(void){
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}