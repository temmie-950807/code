// 46 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
signed main(void){
	fastio;
	
    int n, tmp, s=0;
    vector<int> input;

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end());

    for (int i=0 ; i<n ; i++){
        s += input[i] * (i - (n-i-1));
    }

    cout << s << "\n";
    return 0;
}