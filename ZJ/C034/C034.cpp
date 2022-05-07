#include <iostream>
#include <vector>
using namespace std;

int main(){
    bool check_if_first_number=0;
    int input_pointer;
    const int N=10000;
    vector<int> number(N, 0);
    string input;

    while (cin >> input && input!="0"){
        // init
        input_pointer = 0;

        // add number in vector
        for (int i=N-input.size() ; i<N ; i++){
            number[i] += input[input_pointer++]-'0';
        }
    }

    // make output
    for (int i=N-1 ; i>=9900 ; i--){
        if (number[i]>=10){
            number[i-1] += number[i]/10;
            number[i] %= 10;
        }
    }

    // output
    for (int i=0 ; i<N ; i++){
        if (check_if_first_number) cout << number[i];
        else if(number[i]!=0){
            check_if_first_number=1;
            cout << number[i];
        }

    }
    cout << "\n";

    return 0;
}