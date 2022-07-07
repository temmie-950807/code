// 904 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int unsigned long long
using namespace std;

int cnt[2*(int)10e6+5];
pair<int, int> position[(int)10e4+5];

signed main(void){
	fastio;
	int N;
    int x, y, a, b, k=0;
    double sum=0;

    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> x >> y;
        position[i] = {x,  y};
        for (int j=0 ; j<i ; j++){
            a = position[j].first-position[i].first;
            a *= a;

            b = position[j].second-position[i].second;
            b *= b;
            cnt[a+b]++;
        }
    }

    for (int i=0 ; i<2*(int)10e6+5 ; i++){
        if (cnt[i]>0){
            sum += sqrt(i);
            k++;
        }
    }
    cout << fixed << setprecision(4) << sum/k << "\n";

    return 0;
}