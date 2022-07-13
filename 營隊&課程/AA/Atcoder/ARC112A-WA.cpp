// Problem: A - Not coprime
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)100
using namespace std;

// declare
int n, tmp, output=1;
int input[105][105];
vector<int> prime;

signed main(void){
	fastio;
	
	// pre-process (find prime)
	if (1){
		prime.push_back(2);
		for (int i=3 ; i<=MAX_SIZE ; i++){
			int check = 1;
			for (int j=2 ; j<i ; j++){
				if (i%j==0){
					check = 0;
					break;
				}
			}
			if (check) prime.push_back(i);
		}
	}

	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;

		for (auto x : prime){
			if (x<=tmp && tmp%x==0){
				input[tmp][x] = 1;
			}
		}
	}
	
	// get sum
	for (int i=1 ; i<=100 ; i++){
		for (int j=0 ; j<=100 ; j++){
			if (input[i][j]==1) input[0][j]++;
		}
	}
	
	// process
	while (1){
		int ma=0, pos=0;
		for (int j=0 ; j<=100 ; j++){
			if (input[0][j]>ma){
				ma = input[0][j];
				pos = j;
			}
		}
		
		if (pos==0){
			break;
		}else{
			cout << "pos: " << pos << "\n";
			output *= pos;
		}
		
		for (int i=1 ; i<=100 ; i++){ // 尋找有的質數
			if (input[i][pos]==1){
				for (int j=0 ; j<=100 ; j++){
					input[0][j] -= input[i][j];
				}
			}
		}
	}
	
	cout << output << "\n";
    return 0;
}