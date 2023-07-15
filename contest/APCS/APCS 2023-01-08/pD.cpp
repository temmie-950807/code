// 這題我實在不知道怎麼用簡單的語法寫 包欠 :<

#include <bits/stdc++.h>
using namespace std;

template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}

// 宣告
int n, k;
int l[100005], r[100005];
int ans; // 儲存
vector<pair<int, int>> v; // 每個時間段，用 <結束時間, 開始時間> 儲存
multiset<int> s;

int main(){
    // 輸入
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        cin >> l[i];
    }
    for (int i=0 ; i<n ; i++){
        cin >> r[i];
    }

    // 將每個活動的時間存進 v 裡面，並且排序
    for (int i=0 ; i<n ; i++){
        v.push_back(make_pair(r[i], l[i]));
    }
    sort(v.begin(), v.end());

    // 用 multiset 維護目前借出機器的結束時間
    for (int i=0 ; i<k ; i++){
        s.insert(0);
    }

    for (int i=0 ; i<n ; i++){
        auto it=s.lower_bound(v[i].second); // 搜尋開始時間
        if (it==s.begin()){ // 最早的結束時間和現在的開始時間重疊，因此不能放入（放入一定更糟，必定會影響更多活動）
            continue;
        }

        // 可以借出機器，並且是最近剛使用完的，因為影響最小（其他活動可能會需要更早結束的）
        s.erase(prev(it));
        s.insert(v[i].first);
        ans++;
    }

    // 輸出
    cout << ans << endl;
    return 0;
}