#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
string s1, s2;
vector<string> v;

signed main(void){
	fastio;
	
	// input
	cin >> s1 >> s2;

    for (int i=0 ; i<=s2.size()-s1.size() ; i++){
        int p=0;

        for (int j=0 ; j<s1.size() ; j++){
            if (s1[j]!=s2[i+j]){
                p++;
            }
        }

        if (p<=1){
            v.push_back(s2.substr(i, s1.size()));
        }
    }

    // output
    if (v.size()==0){
        cout << "Not found\n";
    }else{
        sort(v.begin(), v.end());
        for (auto x : v){
            cout << x << "\n";
        }
    }
    return 0;
}