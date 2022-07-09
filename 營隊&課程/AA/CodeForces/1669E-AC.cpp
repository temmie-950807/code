#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, output;
string tmp;
int first[15][15], second[15][15];

// function
int f(int x){
	x-=1;
	return (x*(x+1)/2);
}

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		output=0;
		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	first[tmp[0]-'a'][tmp[1]-'a']++;
        	second[tmp[1]-'a'][tmp[0]-'a']++;
        }
        
        // process
        for (int i=0 ; i<=10 ; i++){
        	for (int j=0 ; j<=10 ; j++){
        		for (int k=0 ; k<j ; k++){
        			output += first[i][j]*first[i][k];
        			output += second[i][j]*second[i][k];
        		}
        	}
        }
        
        // output
        cout << output << "\n";
	}
    return 0;
}