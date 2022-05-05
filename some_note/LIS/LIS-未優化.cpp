#include <bits/stdc++.h>
using namespace std;

int main(){
    // init
    int l[10000],  LIS[10000];
    int N, output=0;
    fill(LIS, LIS+10000, 1);

    // input
    cin >> N;
    for (int i=0 ; i<N ; i++) cin >> l[i];

    // process
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<i ; j++){
            if (l[j]<l[i]){
                LIS[i] = max(LIS[i], LIS[j]+1);
                if (LIS[i]>output) output=LIS[i];
            }
        }
    }

    cout << output << "\n";
    return 0;
}