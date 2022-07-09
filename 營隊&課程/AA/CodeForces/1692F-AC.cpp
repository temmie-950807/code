#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

signed main(void){
	fastio;
	
	// declare
	int t, n, tmp;
	string output;
	
	// input
	cin >> t;
	while (t--){
		// init
		output = "NO\n";
		vector<int> v(10, 0);
		
		// input
		cin >> n;
        for (int i=0 ; i<n ; i++){
        	cin >> tmp;
        	v[tmp%10]++;
        }
        
        // process
        for (int i=0 ; i<10 ; i++){
        	v[i]--;
        	for (int j=0 ; j<10 ; j++){
        		v[j]--;
        		for (int k=0 ; k<10 ; k++){
        			v[k]--;
        			if ((i+j+k)%10==3){
        				int check=1;
	        			for (int l=0 ; l<10 ; l++){
	        				if (v[l]<0){
	        					check=0;
	        					break;
	        				}
	        			}
	        			
	        			if (check){
	        				output = "YES\n";
	        			}
        			}
        			v[k]++;
        		}
        		v[j]++;
        	}
        	v[i]++;
        }
        
        // output
        cout << output;
	}
    return 0;
}