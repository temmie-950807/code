// Problem: D - Hanjo
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int H, W, A, B;
int output = 0;
int table[20][20];

// function
void f(int x, int y){
	if (x==W && y==H){ // 結束條件
		if ((table[y][x]==1) || (table[y][x]==0 && A==1)){
			output++;
			return;
		}
	}else if (x==W && table[y][x]==1){
		f(1, y+1);
	}else if (y==H && table[y][x]==1){
		f(x+1, y);
	}else if (x==W && table[y][x]==0){
		if (A>0){ // 方塊(A)
			A--;
			table[x][y] = 1;
			f(1, y+1);
			A++;
			table[x][y] = 0;
		}

		if (B>0){ // 直塊(B)
			B--;
			table[x][y] = 1;
			table[x][y+1] = 1;
			f(1, y+1);
			B++;
			table[x][y] = 0;
			table[x][y+1] = 0;
		}
	}else if (y==H && table[y][x]==0){
		if (A>0){ // 方塊(A)
			A--;
			table[x][y] = 1;
			f(x+1, y);
			A++;
			table[x][y] = 0;
		}

		if (B>0){ // 橫塊(B)
			B--;
			table[x][y] = 1;
			table[x+1][y] = 1;
			f(x+1, y);
			table[x][y] = 0;
			table[x+1][y] = 0;
		}
	}else if (table[y][x]==0){
		if (A>0){ // 方塊(A)
			A--;
			table[x][y] = 1;
			f(x+1, y);
			A++;
			table[x][y] = 0;
		}

		if (B>0){ // 直塊(B)
			B--;
			table[x][y] = 1;
			table[x][y+1] = 1;
			f(x+1, y);
			B++;
			table[x][y] = 0;
			table[x][y+1] = 0;
		}

		if (B>0){ // 橫塊(B)
			B--;
			table[x][y] = 1;
			table[x+1][y] = 1;
			f(x+1, y);
			table[x][y] = 0;
			table[x+1][y] = 0;
		}
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> H >> W >> A >> B;
	f(1, 1);

	// output
	cout << output << "\n";
    return 0;
}