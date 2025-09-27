#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int fixed_val = -1;
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] != -1) {
            if (a[i] == 0) {
                possible = false;
            }
            if (fixed_val == -1) {
                fixed_val = a[i];
            } else if (fixed_val != a[i]) {
                possible = false;
            }
        }
    }

    if (possible) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
