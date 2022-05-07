#include <iostream>
using namespace std;

int rough_sort(int *list, int left, int right){ // 劃分函數
    int i=left, j=right, pivot=list[left]; // i: 左邊指標, j: 右邊指標, pivot: 基準
    while (i<j){
        while (i<j && list[j]>pivot) j--; // 向左掃描
        if (i<j) swap(list[i++], list[j]);

        while (i<j && list[i]<=pivot) i++; // 向右掃描
        if (i<j) swap(list[i], list[j--]);
    }
    return i;
}

void quick_sort(int *list, int left, int right){
    if (left < right){
        int mid = rough_sort(list, left, right);
        quick_sort(list, left, mid);
        quick_sort(list, mid+1, right);
    }
}

int main(){
    int l[10] = {42, 15, 20, 6, 8, 38, 50, 12};

    quick_sort(l, 0, 7);
    for (int i=0 ; i<8 ; i++){
        cout << l[i] << "\n";
    }
    system("pause");
    return 0;
}