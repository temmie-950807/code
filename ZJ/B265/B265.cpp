#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, input, max, total; // 數量, 輸入, 紀錄最大數, 紀錄總數
    string index; // 雜湊的index
    stringstream ss;

    vector<int> sort_input; // 輸入儲存
    map<string, int> h; // 雜湊表

    while (cin >> n && n!=0){
        // init
        h.clear();
        total = 0;
        max = 0;

        for (int j=0 ; j<n ; j++){
            // input
            sort_input.clear();
            for (int i=0 ; i<5 ; i++){
                cin >> input;
                sort_input.push_back(input);
            }

            // sort
            sort(sort_input.begin(), sort_input.end());
            for (int i=0 ; i<5 ; i++){
            }

            // merge string
            index="";
            for (int i=0 ; i<5 ; i++){
                ss << sort_input[i];
            }
            index += ss.str();
            ss.str("");

            // add count in map
            h[index]++;
        }
        
        // check max
        for (map<string, int>::iterator it=h.begin(); it != h.end(); it++){
            // cout << (*it).first << " " << (*it).second << "\n";
            if ((*it).second > max){
                max = (*it).second;
            }
        }
        // check total
        for (map<string, int>::iterator it=h.begin(); it != h.end(); it++){
            if ((*it).second == max){
                total += max;
            }
        }

        // output
        cout << total << "\n";
    }
    
    return 0;
}