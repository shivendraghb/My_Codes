#include <iostream>

void solve() {
    long long x, y;
    std::cin >> x >> y;
    if (x == y) {
        std::cout << -1 << std::endl;
    } else if (x < y) {
        std::cout << 2 << std::endl;
    } else { // x > y
        if (y > 1 && x - y > 1) {
            std::cout << 3 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
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
