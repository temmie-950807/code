#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int **array = new int *[m]; // 動態二維陣列
    for (int i=0 ; i<m ; i++){
        array[i] = new int [n]; // 動態一維陣列
    }

    for (int i=0 ; i<m ; i++){
        delete [] array[i]; // 釋放一維陣列的記憶體
    }
    delete [] array; // 釋放二維陣列的記憶體
    return 0;
}