#include <bits/stdc++.h>
using namespace std;

// declare
int n, q, k, tmp;
string s1, s2; // s1是目前的字串，s2是即將操作的字串
char arr[1000][1000]; // 用來儲存每一次操作的結果，第arr[i][j]為第i次操作後中第j個字元

int main(){
    cin >> n >> q >> k >> s1;
    s2=s1;

    // 執行操作
    for (int i=1 ; i<=q ; i++){
        // 移動所有字元
        for (int j=0 ; j<n ; j++){
            cin >> tmp;
            s2[tmp-1]=s1[j]; // 請注意，題目給的是從1開始編號，而字串的索引值是從0開始編號
        }

        // 紀錄所有字元
        for (int j=0 ; j<n ; j++){
            arr[i][j]=s2[j];
        }

        // 把「現在的字串」替換成「移動完的字串」
        s1=s2;
    }

    // 輸出結果
    for (int i=0 ; i<k ; i++){
        for (int j=1 ; j<=q ; j++){
            cout << arr[j][i]; // 請注意，由於是從上到下 從左到右輸出，i和j的位子會不同
        }
    }
}