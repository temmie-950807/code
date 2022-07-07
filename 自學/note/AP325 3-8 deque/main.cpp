// AP325 P3-8 O(n) method
#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
deque<int> max_q, min_q;
void put_max(int i){ // 確保是嚴格遞減的deque -> 當移動的時候可以確保最大值一定在front
    while (!max_q.empty() && seq[max_q.back()]<=seq[i]){
        max_q.pop_back();
    }
    max_q.push_back(i);
}
void put_min(int i){ // 確保是嚴格遞增的deque -> 當移動的時候可以確保最小值一定在front
    while (!min_q.empty() && seq[min_q.back()]>=seq[i]){
        min_q.pop_back();
    }
    min_q.push_back(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init & input
    int n, L, input, max_diff=0;
    cin >> n >> L;
    for (int i=0 ; i<n ; i++){
        cin >> input;
        seq.push_back(input);
    }

    put_max(0);
    put_min(0);

    for (int i=1 ; i<n ; i++){
        if (max_q.front()<=i-L){ // deque超過範圍 -> 最大值已不適用
            max_q.pop_front();
        }
        put_max(i);
        if (min_q.front()<=i-L){ // deque超過範圍 -> 最小值已不適用
            min_q.pop_front();
        }
        put_min(i);

        int diff=seq[max_q.front()]-seq[min_q.front()]; // 計算區間差
        max_diff=max(max_diff, diff); // 計算最大區間差
    }

    cout << max_diff << "\n";
    return 0;
}