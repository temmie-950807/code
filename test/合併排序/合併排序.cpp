#include <iostream>
using namespace std;

void  merge(int *list, int left, int mid, int right){
    int *temp_list = new int[right-left+1]; // 輔助陣列
    int l=left, r=mid+1, k=0; // 輔助指標: i: 左陣列指標, r: 右陣列指標, k: 輔助陣列指標
    
    // 將元素比較, 並放進輔助陣列
    while (l<=mid && r<=right){
        if (list[l]<=list[r]){
            temp_list[k++] = list[l++];
        }else{
            temp_list[k++] = list[r++];
        }
    }

    // 將剩下的元素放上去
    while (l<=mid) temp_list[k++] = list[l++];
    while (r<=right) temp_list[k++] = list[r++];

    // 替換陣列
    for (int i=left, k=0 ; i<=right ; i++){
        list[i] = temp_list[k++];
    }

    delete [] temp_list;
}

void merge_sort(int *list , int left, int right){
    if (left<right){
        int mid = (left+right)/2; // 取中點

        // 分割
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);

        // 合併
        merge(list, left, mid, right);
    }
}

int main(){
    int l[10] = {42, 15, 20, 6, 8, 38, 50, 12};
    merge_sort(l, 0, 7);

    for (int i=0 ; i<8 ; i++){
        cout << i << " " << l[i] << "\n";
    }

    system("pause");
    return 0;
}