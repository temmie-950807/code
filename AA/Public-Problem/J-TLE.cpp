// TLE
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int unsigned long long
using namespace std;

signed main(void){
	fastio;
	int N;
    int x, y;
    double sum=0;

    vector<pair<int, int>> input;
    set<double> s;

    cin >> N;
    while (N--){
        cin >> x >>y;
        input.push_back({x, y});
    }

    for (int i=0 ; i<input.size() ; i++){
        for (int j=i+1 ; j<input.size() ; j++){
            x = input[i].first-input[j].first;
            x *= x;

            y = input[i].second-input[j].second;
            y *= y;
            s.insert(sqrt(x+y));
        }
    }
    
    for (auto i : s){
        sum += i;
    }
    cout << fixed << setprecision(4) << sum/s.size() << "\n";

    return 0;
}