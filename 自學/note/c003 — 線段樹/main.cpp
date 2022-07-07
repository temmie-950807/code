#include <bits/stdc++.h>
using namespace std;

// Create Segment Tree
void CreateTree(vector<int> *arr, vector<int> *tree, int node, int start, int end){
    if (start == end){
        (*tree)[node] = (*arr)[start];
    }else{
        int mid = (start+end)/2;
        int left_node = 2*node+1;
        int right_node = 2*node+2;

        CreateTree(arr, tree, left_node, start, mid);
        CreateTree(arr, tree, right_node, mid+1, end);
        (*tree)[node] = max((*tree)[left_node], (*tree)[right_node]);
    }
}

// find max value in range
int QueryTree(vector<int> *arr, vector<int> *tree, int node, int start, int end, int L, int R){
    if (R<start || L>end) return 0;
    else if ((L<=start && end<=R) || start == end){
        return (*tree)[node];
    }else{
        int mid = (start+end)/2;
        int left_node = 2*node+1;
        int right_node = 2*node+2;

        int max_left = QueryTree(arr, tree, left_node, start, mid, L, R);
        int max_right = QueryTree(arr, tree, right_node, mid+1, end, L, R);
        return max(max_left, max_right);
    }
}

int main(){
    // I/O優化
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, P, L, R, total=0;  // arr的數量, 查詢數論, 查詢_1, 查詢_2
    vector<int> arr(2000000); // price
    vector<int> tree(4000000); // Segment Tree

    cin >> N >> P;
    for (int i=0 ; i<N ; i++) cin >> arr[i];
    CreateTree(&arr, &tree, 0, 0, N-1);

    for (int i=0 ; i<P ; i++){
        cin >> L >> R;
        total += QueryTree(&arr, &tree, 0, 0, N-1, L-1, R-1);
    }

    cout << total << "\n";
    return 0;
}