// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         string a, b, c;

//         cin >> n >> a;
//         cin >> m >> b;
//         cin >> c;

//         deque<char> dq(a.begin(), a.end());  // use deque for easy push_front and push_back

//         for (int i = 0; i < m; i++) {
//             if (c[i] == 'V') dq.push_front(b[i]);
//             else dq.push_back(b[i]);
//         }

//         // Convert deque back to string
//         string result(dq.begin(), dq.end());
//         cout << result << "\n";
//     }

//     return 0;
// }
#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;
    int m;
    std::cin >> m;
    std::string b, c;
    std::cin >> b >> c;

    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') {
            a = b[i] + a;
        } else {
            a = a + b[i];
        }
    }
    std::cout << a << std::endl;
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
