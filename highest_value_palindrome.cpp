#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int l = 0, r = n - 1;
    int changes = 0;

    // Phase 1: make it palindrome
    while (l < r) {
        if (s[l] != s[r]) {
            if (s[l] > s[r]) s[r] = s[l];
            else s[l] = s[r];
            changed[l] = changed[r] = true;
            changes++;
        }
        l++; r--;
    }

    if (changes > k) return "-1"; // not enough changes

    int remaining = k - changes;
    l = 0; r = n - 1;

    // Phase 2: maximize the palindrome
    while (l <= r) {
        if (l == r) {
            if (remaining > 0 && s[l] != '9')
                s[l] = '9';
        } else {
            if (s[l] != '9') {
                // If one of them was already changed, we need only 1 more
                if (changed[l] || changed[r]) {
                    if (remaining >= 1) {
                        s[l] = s[r] = '9';
                        remaining--;
                    }
                }
                // If neither changed, we need 2 changes
                else if (remaining >= 2) {
                    s[l] = s[r] = '9';
                    remaining -= 2;
                }
            }
        }
        l++; r--;
    }

    return s;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << highestValuePalindrome(s, n, k) << endl;
    return 0;
}