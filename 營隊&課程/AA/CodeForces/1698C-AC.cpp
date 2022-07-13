// Problem: C. 3SUM Closure
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		v.clear();
		
		// input
		cin >> n;
		int a=0, b=0, c=0; // 正, 負, 零
		for (int i=0 ; i<n ; i++){
			cin >> tmp;
			if (tmp>0){
				a++;
				v.push_back(tmp);
			}else if(tmp<0){
				b++;
				v.push_back(tmp);
			}else{
				c++;
				if (c<3){
					v.push_back(0);
				}
			}
		}
        
        // check
        if (a>=3 || b>=3){
        	cout << "NO\n";
        }else{
        	int check = 1;
        	for (int i=0 ; i<v.size() ; i++){
        		for (int j=0 ; j<i ; j++){
        			for (int k=0 ; k<j ; k++){
        				int s = v[i]+v[j]+v[k];
        				int tmp = 0;
        				
        				for (int l=0 ; l<v.size() ; l++){
        					if (s==v[l]){
        						tmp = 1;
        					}
        				}
        				
        				if (tmp == 0){
        					check = 0;
        				}
        			}
        		}
        	}
        	
        	if (check){
        		cout << "YES\n";
        	}else{
        		cout << "NO\n";
        	}
        }
	}
    return 0;
}