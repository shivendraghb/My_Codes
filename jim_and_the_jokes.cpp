#include <bits/stdc++.h>
using namespace std;

long long toBaseValue(const string &day, int base) {
    long long value = 0;
    for (char c : day) {
        int digit = c - '0';
        if (digit >= base) return -1;
        value = value * base + digit;
    }
    return value;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].first >> events[i].second;
    }

    unordered_map<long long, int> freq;

    for (auto &e : events) {
        int month = e.first;
        string day = e.second;

        if (month < 2) continue;

        long long val = toBaseValue(day, month);
        if (val != -1) {
            freq[val]++;
        }
    }

    long long jokes = 0;
    for (auto &f : freq) {
        long long k = f.second;
        jokes += k * (k - 1) / 2;
    }

    cout << jokes << "\n";
    return 0;
}
