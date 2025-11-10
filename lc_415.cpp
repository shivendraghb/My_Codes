#include <bits/stdc++.h>
using namespace std;

// Two-pointer approach: add from the end of both strings with carry.
class Solution {
public:
    string addStrings(const string& num1, const string& num2) {
        int i = (int)num1.size() - 1;
        int j = (int)num2.size() - 1;
        int carry = 0;
        string res;
        res.reserve(max(num1.size(), num2.size()) + 1);

        while (i >= 0 || j >= 0 || carry) {
            int a = (i >= 0) ? (num1[i--] - '0') : 0;
            int b = (j >= 0) ? (num2[j--] - '0') : 0;
            int sum = a + b + carry;
            res.push_back(char('0' + (sum % 10)));
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

#ifdef LOCAL_TEST
int main() {
    Solution s;
    cout << s.addStrings("243", "564") << "\n"; // 807
    cout << s.addStrings("999", "1") << "\n";   // 1000
    return 0;
}
#endif