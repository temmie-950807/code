#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, total, output;
    int l[100];

    cin >> n;
    while (n--){
        // init
        total=0;
        output=-999999999;

        // input
        cin >> k;
        for (int i=0 ; i<k ; i++){
            cin >> l[i];
        }

        // process
        for (int i=0 ; i<k ; i++){
            total+=l[i];
            if (total>output) output=total;
            if (total<0) total=0;
        }

        // output
        cout << output << "\n";
    }
    
    return 0;
}