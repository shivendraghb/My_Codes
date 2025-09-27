#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int64 h, d;
        cin >> h >> d;

        int64 pos = 0, health = h, consec = 0, turns = 0;

        while (pos < d) {
            int64 need = consec + 1;
            if (health > need) {
                // safe to move
                pos++;
                consec++;
                health -= need;
                turns++;
            } else {
                // must rest
                health++;
                consec = 0;
                turns++;
            }
        }

        cout << turns << "\n";
    }
}
