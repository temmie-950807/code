#include <iostream>
#include <algorithm> // to use reverse
#include <vector> // to use table
using namespace std;

struct info{ // table: value
    int num; // LCS
    int way; // -1: none, 0: left, 1: left+up, 2: up
};

int main(){
    // init
    vector<info> number_table[10000];
    string a, b, output="";

    // input
    cin >> a >> b;
    a = ' '+a, b = ' '+b;

    // get table
    for (int i=0 ; i<=a.size() ; i++){
        for (int j=0 ; j<=b.size() ; j++){
            info k;
            if (i == 0 || j == 0) k.way = -1, k.num = 0; // init table
            else if (a[i] == b[j]) k.way = 1, k.num = number_table[i-1][j-1].num + 1; // left+up
            else if (number_table[i-1][j].num < number_table[i][j-1].num) k.way = 0, k.num = number_table[i][j-1].num; // left
            else k.way = 2, k.num = number_table[i-1][j].num; // up

            number_table[i].push_back(k);
        }
    }

    /*
    // print table
    for (int i=0 ; i<a.size()-1 ; i++){
        for (int j=0 ; j<b.size()-1 ; j++) cout << number_table[i][j].num << " ";
        cout << "\n";
    }
    */

    // get output
    int i=a.size()-1, j=b.size()-1;
    while (number_table[i][j].way != -1){
        switch (number_table[i][j].way){
            case 0:
                j--;
                break;
            case 2:
                i--;
                break;
            case 1:
                output += a[i];
                i--, j--;
                break;
        }
    }

    // output
    reverse(output.begin(), output.end());
    cout << output << "\n";
    
    return 0;
}