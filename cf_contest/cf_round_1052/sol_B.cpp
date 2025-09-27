#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> sets(n);
    std::vector<int> freq(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;
        sets[i].resize(l);
        for (int j = 0; j < l; ++j) {
            std::cin >> sets[i][j];
            freq[sets[i][j]]++;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (freq[i] == 0) {
            std::cout << "NO\n";
            return;
        }
    }

    int non_essential_count = 0;
    for (int i = 0; i < n; ++i) {
        bool is_non_essential = true;
        for (int element : sets[i]) {
            if (freq[element] <= 1) {
                is_non_essential = false;
                break;
            }
        }
        if (is_non_essential) {
            non_essential_count++;
        }
    }

    if (non_essential_count >= 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
