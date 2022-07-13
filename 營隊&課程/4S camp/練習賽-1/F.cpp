// Problem: F. 網頁設計 (Web Develop)
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
int t;
string s, tmp;
stack<string> sta;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	cin.ignore();
	while (t--){
		getline(cin, s);
		int check = 0;
		if (s[s.size()-1]=='>'){
			for (int i=s.size()-2 ; i>=0 ; i--){
				if (s[i]==' '){
					continue;
				}else if (s[i]=='/'){
					check = 1;
					break;
				}else{
					break;
				}
			}
		}
		
		if (check==1){
			// dont need do anything
		}else if (s[0]=='<' && s[1]=='/' && s[s.size()-2]=='/' && s[s.size()-1]=='>'){
			cout << "NO\n";
			return 0;
		}else if (s[0]=='<' && s[1]=='/' && s[s.size()-1]=='>'){
			// check stack top
			if (sta.empty()){
				cout << "NO\n";
				return 0;
			}else{
				// cout << "A: " << sta.top() << "\n";
				// cout << "B: " << s.substr(2, s.size()-3) << "\n";
				tmp = "";
				for (int i=0 ; i<s.size() ; i++){
					if (s[i]=='<' || s[i]=='/'){
						continue;
					}else if (s[i]==' ' || s[i]=='>'){
						break;
					}else{
						tmp += s[i];
					}
				}
				if (sta.top() != tmp){
					cout << "NO\n";
					return 0;
				}else{
					sta.pop();
				}
			}

		}else if (s[0]=='<' && s[s.size()-1]=='>'){
			// push in stack
			tmp = "";
			for (int i=0 ; i<s.size() ; i++){
				if (s[i]=='<'){
					continue;
				}else if (s[i]==' ' || s[i]=='>'){
					break;
				}else{
					tmp += s[i];
				}
			}
			
			// cout << "push element: " << tmp << "\n";
			sta.push(tmp);
		}else{
			// dont need do anything
		}
	}

	if (sta.size()>0){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
    return 0;
}