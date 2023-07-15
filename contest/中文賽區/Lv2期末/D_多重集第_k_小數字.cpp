#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#if !LOCAL
#define endl "\n"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// declare
const int MAX_SIZE = (1<<23)+5;

int ans=0;
vector<int> BIT(MAX_SIZE);

// function
void update(int pos, int val){
    for (int i=pos ; i<MAX_SIZE ; i+=i&-i){
        BIT[i]+=val;
    }
}

int query(int pos){
    int ret=0;
    for (int i=pos ; i>0 ; i-=i&-i){
        ret+=BIT[i];
    }
    return ret;
}

int k_th(int k){
    int now=0;
    for (int i=22 ; i>=0 ; i--){
        if (BIT[now+(1<<i)]<k){
            k-=BIT[now+(1<<i)];
            now+=(1<<i);
        }
    }
    return now+1;
}

// solve
const int MOD = 1000000007;
unsigned int get_next_value(unsigned int &seed) {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}
void gen_input() {
    int Q, V, ratio;
    unsigned int seed;
    cin >> Q >> V >> ratio >> seed;
    int num = 0;
    for(int i = 1; i <= Q; i++) {
        int query_type = 1;
        if(i > 1) query_type = get_next_value(seed) % ratio ? 2 : 1;
        // query_type 代表第 i 個詢問是第幾種類型的操作
        if(num == 0 || query_type == 1) {
            int x, k; // x, k 代表第一種詢問類型的兩個參數
            x = get_next_value(seed) % V + 1;
            k = get_next_value(seed) % 100 + 1;
            num += k;
            update(x, k);
            // cout << query_type << " " << x << " " << k << endl;

        } else if(query_type == 2) {
            int k; // k 代表第二種詢問類型的兩個參數
            k = get_next_value(seed) % num + 1;
            // cout << query_type << " " << k << endl;
            // cout << k_th(k) << endl;
            ans^=k_th(k);
        }

        cout << endl;
    }
}

int main(){
    gen_input();
    cout << ans << endl;
    return 0;
}