#include <iostream>

void solve() {
    int n, ans, lines;

    // Query 1: Find if W is 10^5.
    std::cout << "? 1 100000" << std::endl;
    std::cin >> lines;

    if (lines == 1) {
        // W >= 100000, so W must be 100000.
        ans = 100000;
    } else {
        // W < 100000. Use the second query to find the exact value.
        std::cout << "? 99999";
        for (int i = 0; i < 99999; ++i) {
            std::cout << " 1";
        }
        std::cout << std::endl;
        std::cin >> lines;

        // W is the number of words per line.
        // lines = ceil(99999.0 / W).
        // lines-1 < 99999.0/W <= lines.
        // W <= 99999.0/(lines-1) and W > 99999.0/lines.
        // Since W is integer, W = floor(99999.0/(lines-1))
        ans = 99999 / (lines - 1);
    }

    std::cout << "! " << ans << std::endl;
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
