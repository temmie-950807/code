// Problem: Message Route
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

// declare
int n, m, a, b;
bool check=0;
vector<int> G[MAX_SIZE], from(MAX_SIZE, -1), output;
queue<int> BFS;
bitset<MAX_SIZE> pass(0);

// function
void back(int index){
	if (index==1){
		output.push_back(index);
		return;
	}else{
		output.push_back(index);
		back(from[index]);
		return;
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
	for (int i=0 ; i<m ; i++){
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	
	BFS.push(1);
	pass[BFS.front()]=1;
	while (!BFS.empty()){
		// check end
		if (BFS.front()==n){
			check=1;
			break;
		}
		
		for (auto x : G[BFS.front()]){
			if (pass[x] == 0){
				BFS.push(x);
				pass[x]=1; // 紀錄已經經過
				from[x] = BFS.front();
			}
		}
		
		BFS.pop();
	}
	
	if (check == 1){
		back(n);
		reverse(output.begin(), output.end());
		cout << output.size() << "\n";
		for (auto x : output){
			cout << x << " ";
		}
	}else{
		cout << "IMPOSSIBLE\n";
	}
    return 0;
}