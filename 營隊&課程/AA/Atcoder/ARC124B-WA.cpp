// Problem: B - XOR Matching 2
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
 
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2000;
using namespace std;
 
// declare
int n, tmp;
vector<int> a, b, p, output;
map<int, int> m;
 
signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		b.push_back(tmp);
		p.push_back(a[0]^tmp);
	}
	
	// pre-process
	p.erase(unique(p.begin(), p.end()), p.end());
	sort(p.begin(), p.end());
	for (auto x : p){
		m[x] = 0;
	}
	
	// process
	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			if (m.find(a[i]^b[j]) != m.end()){
				m[a[i]^b[j]]++;
				if (m[a[i]^b[j]]==n){
					output.push_back(a[i]^b[j]);
				}
			}
		}
	}
	
	// output
	sort(output.begin(), output.end());
	cout << output.size() << "\n";
	for (auto x : output){
		cout << x << "\n";
	}
    return 0;
}