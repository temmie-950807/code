#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,fma,avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

// declare
const int N=5;
uint64_t x, n, total;
uint64_t arr[N];

int f(int n){
    int ans=0;
    for (int i=0 ; i<64 ; i++){
        ans+=n;
        n>>=1;
    }
    return ans;
}

void solve1(){

    // input
    cin >> x >> n;

    // process
    int i=1;
    arr[0]=x;
    for( ; i<n; i++) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        arr[i%5]=x;

        if (i%N==0){
            for (int k=0 ; k<N ; k++){
                cerr << arr[k] << " ";
            }   cerr << "\n";
            for (int j=0 ; j<64 ; j++){
                for (int k=0 ; k<N ; k++){
                    total+=arr[0];
                    total+=arr[1];
                    total+=arr[2];
                    total+=arr[3];
                    total+=arr[4];
                    arr[0]>>=1;
                    arr[1]>>=1;
                    arr[2]>>=1;
                    arr[3]>>=1;
                }
            }
        }
    }

    for (int k=0 ; k<i%N ; k++){
        cerr << arr[k] << " ";
    }   cerr << "\n";
    for (int k=0 ; k<64 ; k++){
        for (int j=0 ; j<i%N ; j++){
            total+=arr[j];
            arr[j]>>=1;
        }
    }

    // output
    cout << total << endl;

    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}