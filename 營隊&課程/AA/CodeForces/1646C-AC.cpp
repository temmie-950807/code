#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
int t, input, s, b, k, tmp;
int output, o1, o2;
int factorial[100];

signed main(void){
	fastio;

    // get "factorial"
    factorial[0] = 1;
    for (int i=1 ; i<16 ; i++){
        factorial[i] = factorial[i-1]*i;
    }

    // input
    cin >> t;
    for (int i=0 ; i<t ; i++){
        // init
        output = 2e18;
        b = 0; // 窮舉

        // input;
        cin >> input;

        // enumerate
        while (b < (1<<15)){
            // factorial
            s = 0; // 窮舉階乘的和
            k = 0; // 1的數量
            for (int j=0 ; j<16 ; j++){
                s += ((b>>j)&1) * factorial[j];
                k += ((b>>j)&1);
            }

            if (s > input){
                b++;
                continue;
            }

            // pow of 2
            tmp = max((int)0, input - s);
            int z = tmp;
            while (tmp > 0){
                k += (tmp&1);
                tmp >>= 1;
            }
            
            // final
            if (output > k){
                output = k;
            }
            b++;
        }

        // output
        if (output == 2e18){
            cout << "-1\n";
        }else{
            cout << output << "\n";
        }
    }

    return 0;
}