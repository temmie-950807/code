#include <bits/stdc++.h>
using namespace std;

int main(){
    int f;
    vector<int> v;

    // 隨機生成測資
    srand(time(NULL));
    for (int i=0 ; i<10 ; i++){
        v.push_back(rand()%10);
    }

    sort(v.begin(), v.end());
    for (int i=0 ; i<10 ; i++){
        cout << v[i] << " ";
    }cout << "\n";

    f=lower_bound(v.begin(), v.end(), 8)-v.begin(); // if f=10(v.end) 就代表沒找到
    cout << f << "\n"; // 回傳index

    f=lower_bound(v.begin(), v.end(), 8, greater<int>())-v.begin(); // if f=10(v.end) 就代表沒找到
    cout << f << "\n"; // 回傳index
    return 0;
}