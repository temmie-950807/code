// Problem: B. Polycarp Writes a String from Memory
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
int t, s;
string n;
char a, b, c;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		a=' ';
		b=' ';
		c=' ';
		s=0;
		
		// input
		cin >> n;
		n += '*';
		
		int i=0;
		int check=0;
        while (i<n.size()){
        	if (n[i]=='*'){
        		s++;
        		break;
        	}else if (check == 1){
        		a=' ';
				b=' ';
				c=' ';
        		s++;
        		check = 0;
        	}else{
        		if (n[i]==a || n[i]==b || n[i]==c){
        			i++;
        		}else if (a==' '){
        			a=n[i];
        			i++;
        		}else if (n[i]!=a && b==' '){
        			b=n[i];
        			i++;
        		}else if (n[i]!=a && n[i]!=b  && c==' '){
        			c=n[i];
        			i++;
        		}else{
        			check = 1;
        		}
        		
        	}
        }
        
        // output
        cout << s << "\n";
	}
    return 0;
}