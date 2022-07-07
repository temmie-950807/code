#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    
    int n, s=0;
    int a, b;
    vector<int> output;

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        if (b > 100){
            output.push_back(a);
            s += 5*(b-100);
        }
    }

    sort(output.begin(), output.end());

    if (output.size()>0){
        for (auto x : output){
            cout << x << " ";
        }   cout << "\n";
    }
    cout << s << "\n";
    
    return 0;
}