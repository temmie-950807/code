// Problem: B. Fair Numbers
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
int t, n, tmp;
bool check;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// input
		cin >> n;
        
        while (1){
        	// init
        	vector<int> num(10, 0);
        	check = 1;
        	tmp = n;
        
        	// get num
        	while (tmp != 0){
        		num[tmp%10] = 1;
        		tmp /= 10;
        	}
        	
        	// process
        	for (int i=1 ; i<10 ; i++){
        		if (num[i]==0){
        			continue;
        		}else{
        			if (n%i!=0){
        				check = 0;
        			}
        		}
        	}
        	
        	// output
        	if (check){
        		cout << n << "\n";
        		break;
        	}
        	
        	// final
        	n++;
        }
	}
    return 0;
}