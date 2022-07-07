#include <iostream>
#include <bitset>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    bitset<32> b;

    while (cin >> n){
        b=n;
        if (b.count() == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}