#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

const int max_N = 1000;

void build_segment_tree(vector<int> *input, vector<int> *segment_tree, int node, int start, int end){
	if (start == end){
		(*segment_tree)[node] = (*input)[start];
	}else{
		int mid = (start+end)/2;
		int left_node = node*2 + 1;
		int right_node = node*2 + 2;

		build_segment_tree(input, segment_tree, left_node, start, mid);
		build_segment_tree(input, segment_tree, right_node, mid+1, end);
		(*segment_tree)[node] = (*segment_tree)[left_node] + (*segment_tree)[right_node];
	}
}

void update_segment_tree(vector<int> *input, vector<int> *segment_tree, int node, int start, int end, int index, int value){
	if (start == end){
		(*input)[index] = value;
		(*segment_tree)[node] = value;
	}else{
		int mid = (start+end)/2;
		int left_node = node*2 + 1;
		int right_node = node*2 + 2;
		
		if (index >= start && index <= mid){
			// go to left tree
			update_segment_tree(input, segment_tree, left_node, start, mid, index, value);
		}else{
			// go to right tree
			update_segment_tree(input, segment_tree, right_node, mid+1, end, index, value);
		}

		(*segment_tree)[node] = (*segment_tree)[left_node] + (*segment_tree)[right_node]; // update
	}	
}

int query_segment_tree(vector<int> *input, vector<int> *segment_tree, int node, int start, int end, int L, int R){
	cout << "start: " << start << " end: " << end << "\n";
	
	if (R < start || L > end){
		return 0;
	}else if (start == end || (L <= start && R >= end)){
		return (*segment_tree)[node];
	}else{
		int mid = (start+end)/2;
		int left_node = node*2 + 1;
		int right_node = node*2 + 2;
		int sum_left  = query_segment_tree(input, segment_tree, left_node  , start, mid, L, R);
		int sum_right = query_segment_tree(input, segment_tree, right_node , mid+1, end, L, R);
		return sum_left+sum_right;
	}
}

signed main(void){
	// fastio;
	int n, tmp;
	vector<int> input;
	vector<int> segment_tree(max_N, 0);	
    
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		input.push_back(tmp);
	}
	
	build_segment_tree(&input, &segment_tree, 0, 0, n-1);
	update_segment_tree(&input, &segment_tree, 0, 0, n-1, 4, 6);
	int s = query_segment_tree(&input, &segment_tree, 0, 0, n-1, 2, 5);
	cout << s << "\n";


	for (int i=0 ; i<20 ; i++){
		cout << segment_tree[i] << " ";
	}cout << "\n";
	return 0;
}