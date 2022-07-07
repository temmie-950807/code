#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, input, output, pointer;
    vector<int> a, b;

    while (cin >> n >> m && n!=0 && m!=0){
        // init
        output=0;
        pointer=0;
        a.clear();
        b.clear();

        // input
        for (int i=0 ; i<n ; i++){
            cin >> input;
            a.push_back(input);
        }
        for (int i=0 ; i<m ; i++){
            cin >> input;
            b.push_back(input);
        }

        // sort
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // process
        for (int i=0 ; i<m ; i++){
            if (b[i]>=a[pointer]){
                pointer++;
                output+=b[i];

                if (pointer==a.size()){
                    break;
                }
            }
        }

        // output
        if (pointer==a.size()) cout << output << "\n";
        else cout << "Loowater is doomed!\n";
    }


    return 0;
}