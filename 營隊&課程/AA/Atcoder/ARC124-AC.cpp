#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int n, a, b, output=1, check;
    vector<int> input_A, input_B;
    vector<int> factor_A, factor_B;

    // init
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        input_A.push_back(a);
        input_B.push_back(b);
    }

    // get factor
    // O(1e9)
    for (int i=1  ; i*i <= input_A[0] ; i++){
        if (input_A[0] % i == 0) factor_A.push_back(i), factor_A.push_back(input_A[0]/i);
    }
    for (int i=1  ; i*i <= input_B[0] ; i++){
        if (input_B[0] % i == 0) factor_B.push_back(i), factor_B.push_back(input_B[0]/i);
    }

    // enumerate
    // O(2e3 * 2e3 * 50)
    for (int i=0 ; i<factor_A.size() ; i++){
        for (int j=0 ; j<factor_B.size() ; j++){
            check = 1;
            for (int k=1 ; k<n ; k++){
                if ((input_A[k]%factor_A[i]==0 && input_B[k]%factor_B[j]==0) || (input_A[k]%factor_B[j]==0 && input_B[k]%factor_A[i]==0)){
                    continue;
                }else{
                    check = 0;
                    break;
                }
            }

            if (check){
                output = max(output, factor_A[i]*factor_B[j] / __gcd(factor_A[i], factor_B[j]));
            }
        }
    }

    // output
    cout << output << "\n";
    return 0;
}