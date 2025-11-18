// #include <bits/stdc++.h>
// using namespace std;
// int j = 1;
// void towerOfHanoi(int n, char from, char aux, char to) {
//     if (n == 0) return;
//     towerOfHanoi(n - 1, from, to, aux);
//     cout << j++ << "Move disk " << n << " from " << from << " to " << to << "\n";
//     towerOfHanoi(n - 1, aux, from, to);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         towerOfHanoi(n, 'A', 'B', 'C');
//     }
// }
#include<bits/stdc++.h>
using namespace std;

#define int long long
int j = 1;
void towerOfHanoi(int n, char from, char aux, char to) {
    if(n == 0) return;
    towerOfHanoi(n - 1, from, to, aux);
    cout << j++ << " Move disk " << n << " from " << from << " to " << to << '\n';
    towerOfHanoi(n - 1, aux, from, to);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        towerOfHanoi(n, 'A', 'B', 'C');
    }
}