// Problem: Tree Traversals
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5

using namespace std;
using namespace __gnu_pbds;

// declare
int n, tmp;
vector<int> A(MAX_SIZE, 0), pos(MAX_SIZE, 0); // 前序, 中序
vector<int> tree[MAX_SIZE];

void f(int l1, int r1, int l2, int r2){
	// 1: 針對前序
	// 2: 針對中序
	
	if (l1>r1) return;
	if (l1==r1){
		cout << A[l1] << " ";
		return;
	}
	
	int mid = pos[A[l1]]; // 前序的第一個在中序的位置
	// 左子樹
	f(l1+1, l1+mid-l2, l2, mid-1);
	// 1. l1+1:      因為A[l1]是父節點, 下一個遞迴不須理會
	// 2. l1+mid-l2: 因為沒辦法直接找到切割點(左子樹與右子樹的交界), 因此用相對距離處理
	//               (mid-l2)為左子樹的長度, 加上l1之後就是分割點
	// 3. l2:        B的左界不變
	// 4. mid-1:     以父節點切割, 左邊(-1)就是右界
	
	// 右子樹
	f(l1+mid-l2+1, r1, mid+1, r2);
	// 1. l1+mid-l2+1: 同左子樹(2.)+1
	// 2. r1:          A的右界不變
	// 3. mid+1:       以父節點切割, 右邊(+1)就是右界
	// 4. r2:          B的右界不變
	cout << A[l1] << " ";
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=1 ; i<=n ; i++){
		cin >> tmp;
		A[i] = tmp;
	}
	for (int i=1 ; i<=n ; i++){
		cin >> tmp;
		pos[tmp] = i;
	}
	
	// recursive
	f(1, n, 1, n);
	
    return 0;
}