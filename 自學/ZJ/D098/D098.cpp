#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int sum, num;
    bool check;
    string input;
    stringstream ss;

    while (getline(cin, input)){
        input += " ";

        // init
        sum = 0;
        check = 0;

        // process
        for (int i=0 ; i<input.size() ; i++){
            if (input[i] == ' '){
                if (!check){
                    ss >> num;
                    sum += num;
                }
                num = 0;
                check = 0;
                ss.clear();
                ss.str("");

            }else if (isdigit(input[i])){
                ss << input[i];
            }else if (!isdigit(input[i])){
                check = 1;
            }
        }

        // output
        cout << sum << "\n";
    }
    
    // system("pause");
    return 0;
}