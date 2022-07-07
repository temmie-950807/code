// 93 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    int t, n, k, tmp;
    int output[MAX_SIZE];
    string input;

    cin >> t;
    for (int _=0 ; _<t ; _++){
        // init
        memset(output, 0, sizeof(output));

        // input
        cin >> n >> k >> input;
        tmp = k;

        // process
        for (int i=0 ; i<n ; i++){
            if (k%2==0){
                if (input[i] == '0' && tmp>0){
                    output[i]++;
                    tmp--;
                }
            }else{
                if (input[i] == '1' && tmp>0){
                    output[i]++;
                    tmp--;
                }
            }
        }
        output[n-1]+=tmp;

        // output
        for (int i=0 ; i<n ; i++){
            if (k%2 == 0){
                if (output[i]%2 == 0){
                    cout << (char)input[i];
                }else{
                    cout << (input[i]=='0'); 
                }
            }else{
                if (output[i]%2 == 0){
                    cout << (input[i]=='0'); 
                }else{
                    cout << (char)input[i];
                }
            }
        }cout << "\n";

        for (int i=0 ; i<n ; i++){
            cout << output[i] << " ";
        }   cout << "\n";
    }
	
    
    return 0;
}