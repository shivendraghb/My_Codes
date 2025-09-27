#include<bits/stdc++.h>
using namespace std;

bool wouldBeBad(const vector<int>& q, int newVal) {
    vector<int> temp = q;
    temp.push_back(newVal);
    int n = temp.size();

    if (n < 5) return false;

    // Only check the window that ends with the new element
    int start = n - 5;
    bool inc = true, dec = true;

    for (int i = start; i < start + 4; i++) {
        if (temp[i] >= temp[i + 1]) inc = false;
        if (temp[i] <= temp[i + 1]) dec = false;
    }

    return inc || dec;
}

string solve(vector<int> p) {
    int n = p.size();
    string result = "";
    vector<int> q;
    int left = 0, right = n - 1;

    while (left <= right) {
        bool leftSafe = !wouldBeBad(q, p[left]);
        bool rightSafe = !wouldBeBad(q, p[right]);

        if (leftSafe && rightSafe) {
            // Both safe, choose left (simple heuristic)
            q.push_back(p[left]);
            result += 'L';
            left++;
        } else if (leftSafe) {
            q.push_back(p[left]);
            result += 'L';
            left++;
        } else if (rightSafe) {
            q.push_back(p[right]);
            result += 'R';
            right--;
        } else {
            // This case shouldn't happen if a solution always exists
            // But as fallback, try left
            q.push_back(p[left]);
            result += 'L';
            left++;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        cout << solve(p) << '\n';
    }

    return 0;
}
