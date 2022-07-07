#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int cnt=0;
    set<int> s;

    // init
    s.clear();
    s.insert(1);
    
    // process
    for (auto it=s.begin() ; it!=s.end() ; it++){
        ++cnt;
        if (cnt == 1500) {
            cout << "The 1500'th ugly number is " << *it << "." << endl;
            return 0;
	    }
        s.insert(*it*2);
        s.insert(*it*3);
        s.insert(*it*5);
    }
    
    return 0;
}