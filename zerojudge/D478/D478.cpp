#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, input;
    cin >> n >> m;

    while (n--){
        vector<int> v;
        set<int> s;

        for (int i=0 ; i<m ; i++){
            cin >> input;
            v.push_back(input);
            s.insert(input);
        }
        for (int i=0 ; i<m ; i++){
            cin >> input;
            v.push_back(input);
            s.insert(input);
        }

        cout << v.size()-s.size() << "\n";
    }
}