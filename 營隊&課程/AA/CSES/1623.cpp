// 0.15 s
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

bool get_bit(int a, int b){
    return ((a>>b)&1);
}

signed main(void){
	fastio;
    
    int n, tmp, p;
    int g1, g2;
    int output=1e18;
    vector<int> input;

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    while (p<pow(2, n)){
        // init
        g1=0, g2=0;

        // get group
        for (int i=0 ; i<n ; i++){
            if (get_bit(p, i)){
                g1 += input[i];
            }else{
                g2 += input[i];
            }
        }

        // final
        output = min(output, abs(g1-g2));
        p++;
    }

    cout << output << "\n";
    return 0;
}