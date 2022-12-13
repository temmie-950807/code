// Problem: D. Not a Cheap String
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)5200000
using namespace std;

struct Data{
	char c;
	int index;
};

// declare
int t, n, total;
string s;
vector<Data> process;

// function
bool cmp_1(Data A, Data B){
	if (A.c == B.c){
		return A.index<B.index;
	}else{
		return A.c<B.c;
	}
}

bool cmp_2(Data A, Data B){
	return A.index<B.index;
}

signed main(void){
	// fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		process.clear();
		total = 0;
		
		// input
		cin >> s >> n;
		for (int i=0 ; i<s.size() ; i++){
			total += s[i]-'a'+1;
			process.push_back({s[i], i});
		}

        sort(process.begin(), process.end(), cmp_1);
		

		while (total>n  && process.size()!=0){
			// cout << "total: " << total << "\n";
			// cout << "minus: " << process[process.size()-1].c-'a' << "\n";
			total -= (process[process.size()-1].c-'a'+1);
			process.pop_back();
		}
		
        sort(process.begin(), process.end(), cmp_2);

		for (auto x : process){
			cout << x.c << "";
		}
		cout << "\n";

	}
    return 0;
}