#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    if (n % 2 == 0) {
        for (int i = n - n / 2; i < n; i++) {
            std::cout << i << " ";
        }
        for (int i = n + 1; i <= n + n / 2; i++) {
            std::cout << i << " \n"[i == n + n / 2];
        }
    } else {
        int d = (n + 1) / 2;
        for (int i = n + 2 - d; i <= n; i++) {
            std::cout << i << " ";
        }
        std::cout << " | ";
        for (int i = n + 3; i <= n + 2 + d; i++) {
            std::cout << i << " \n"[i == n + 2 + d];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}