// Problem: B. Prinzessin der Verurteilung
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n;
string tmp;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> n >> tmp;
        
        for (int i=0 ; i<=3000 ; i++){
        	// get find string
        	string find="";
        	if (i>=702){
        		find += (char)(i/702-1+'a');
        		find += (char)(i%702/26+'a');
        	}else if (i>=26){
        		find += (char)(i/26-1+'a');
        	}
        	if (1){
        		find += (char)(i%26+'a');
        	}
        	
        	// check if "find" in string
        	int check = 0;
        	for (int i=0 ; i<=tmp.size() ; i++){
        		if (tmp.substr(i, find.size())==find){
        			check = 1;
        		}
        	}
        	
        	// output
        	if (check==0){
        		cout << find << "\n";
        		break;
        	}
        }
	}
    return 0;
}