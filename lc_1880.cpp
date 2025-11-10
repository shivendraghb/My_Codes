#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSumEqual(const string& firstWord, const string& secondWord, const string& targetWord) {
        auto toNum = [](const string& w) {
            long long v = 0;
            for (char ch : w) v = v * 10 + (ch - 'a');
            return v;
        };
        return toNum(firstWord) + toNum(secondWord) == toNum(targetWord);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string firstWord, secondWord, targetWord;
    if (!(cin >> firstWord >> secondWord >> targetWord)) return 0;

    Solution sol;
    cout << (sol.isSumEqual(firstWord, secondWord, targetWord) ? "true" : "false") << '\n';
    return 0;
}