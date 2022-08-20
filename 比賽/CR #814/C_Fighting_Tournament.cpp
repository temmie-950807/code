#include <bits/stdc++.h>
const int MAX_SIZE = 1e5+5;
using namespace std;

// declare
int v[MAX_SIZE];

signed main(void){
    
    for (int i=0 ; i<10000 ; i++){
        // memset(v, i, sizeof(v)); // 156ms
        // fill(v, v+MAX_SIZE, i); // 296ms
        // memset(v, 0, sizeof(v)); // 186ms
        fill(v, v+MAX_SIZE, i); // 343ms
    }

    return 0;
}