// Problem: C. Infected Tree
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

const int max_N = 3*10e5 + 5;
int t, n; // t: 1~5000, n: 2~3*10e5
int parent, child, infect_node; // infect_node: 目前受感染的節點
int total; // aka output
vector<int> tree[max_N]; // tree[i] = [value, left node, right node];
                         // 維護此樹每個value都是子節點數量

int get_total_child(int node){
	if (tree[node].size()==1){
		tree[node][0]=0;
		return 0;
	}else if (tree[node].size()==2){
		get_total_child(tree[node][1]);
		tree[node][0]=tree[tree[node][1]][0]+1;
		return tree[node][0];
	}else{
		get_total_child(tree[node][1]);
		get_total_child(tree[node][2]);
		tree[node][0]=tree[tree[node][1]][0]+tree[tree[node][2]][0]+2;
		return tree[node][0];
	}
	
	return 0;
}

signed main(void){
	// fastio;
	
	cin >> t;
	while (t--){
		// init
		infect_node=1;
		total=0;
		for (int i=0 ; i<max_N ; i++){
			tree[i].clear();
			tree[i].push_back(0); // total child
		}
		
		// input
		cin >> n;
		for (int i=0 ; i<n-1 ; i++){
			cin >> parent >> child;
			tree[parent].push_back(child); // child
		}
		
		// get total child;
		get_total_child(1);
		
		while (1){
			cout << __LINE__ << " " << infect_node << "\n";
			if (tree[infect_node][0]==0){
				break;
			}else if (tree[infect_node].size()==1){
				total += tree[tree[infect_node][1]][0];
				break;
			}else if (tree[infect_node].size()==2){
				if (tree[tree[infect_node][1]][0] > tree[tree[infect_node][2]][0]){ // 左節點>右節點
					total += tree[tree[infect_node][1]][0]; // 保護左節點
					infect_node = tree[infect_node][2];
				}else{
					total += tree[tree[infect_node][2]][0]; // 保護右節點
					infect_node = tree[infect_node][1];
				}
			}
		}
		
		// output
		cout << total << "\n";
	}
	return 0;
}