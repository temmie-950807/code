// 186 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	
    string s;
    int q, x, k=0, ss; // k = 第一個字元的原始位置, ss = s.size()
    int index;
    char c;

    cin >> s >> q;
    ss = s.size();
    for (int i=0 ; i<q ; i++){
        cin >> c >> x;

        if (c == 'A'){
            x--;

            index = k+x;
            if (index >= 0){
                index %= ss; // 確保正整數都在s.size()內
            }else{
                index %= -ss;
                index += ss;
            }

            cout << s[index] << "\n";
        }else{
            k += x;
        }
    }

    return 0;
}

// abcde
// 4
// M -1
// A 1
// M -1
// A 1

// abcde
// 4
// M 3
// A 1
// M 3
// A 1