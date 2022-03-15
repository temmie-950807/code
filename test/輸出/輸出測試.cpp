#include <iostream>
// #include <iomanip>
using namespace std;

int main(){
    int n;
    double b;
    cin >> n >> b;
    cout << scientific << n << "\n";
    cout << scientific << b << "\n";

    // 浮點數設定 - iomanip
        // setprecision - 設定精度
        // setw         - 設定寬度
        // setfill      - 設定填補字元
    // 設定輸出
        // oct          - 八進位格式輸出
        // dec          - 十進位格式輸出
        // hex          - 十六進位格式輸出
        // ==============================
        // left         - 向左對齊
        // right        - 向右對齊
        // scientific   - 以科學符號輸出(浮點數)
        // fixed        - 固定點數

    system("pause");
    return 0;
}