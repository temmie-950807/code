#include <bits/stdc++.h>
using namespace std;

// 宣告變數
int k;
int t[10], s[10];
int max_score=-1, max_time=-1, cnt=0; // 嚴重錯誤的次數

int main(){
    // 輸入所有變數
    cin >> k;
    for (int i=0 ; i<10 ; i++){
        cin >> t[i] >> s[i];
    }

    // 檢查所有提交紀錄
    for (int i=0 ; i<k ; i++){
        if (s[i]==-1){
            // 如果是嚴重錯誤的話，就將次數+1
            cnt=cnt+1;
        }else if (s[i]>max_score){
            // 如果現在的分數比之前紀錄的高的話，就更新最大值
            max_score=s[i];
            max_time=t[i];
        }
    }

    // 輸出
    if (max_score-k-(2*cnt)<0){
        // 如果計算的結果小於0的話就輸出總分為0
        cout << 0 << " " << max_time << endl;
    }else{
        cout << max_score-k-(2*cnt) << " " << max_time << endl;
    }
}