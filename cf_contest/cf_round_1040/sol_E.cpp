#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to handle the interactive query
int query(const vector<int>& indices) {
    cout << "? " << indices.size();
    for (int idx : indices) {
        cout << " " << idx;
    }
    cout << endl;
    int result;
    cin >> result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<char> ans(n);
        int open_ref_idx = -1;
        int close_ref_idx = -1;

        // Find a pair of indices (p, q) with f(s_p s_q) = 1.
        // This guarantees s_p = '(' and s_q = ')'.
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                vector<int> indices = {i, j};
                if (query(indices) == 1) {
                    open_ref_idx = i;
                    close_ref_idx = j;
                    goto found_pair; // A simple way to break out of nested loops
                }
            }
        }

    found_pair:;

        // Use the found pair to set the initial characters
        ans[open_ref_idx - 1] = '(';
        ans[close_ref_idx - 1] = ')';

        // Determine the rest of the characters using the known '(' reference
        for (int i = 1; i <= n; ++i) {
            if (i == open_ref_idx || i == close_ref_idx) {
                continue;
            }

            vector<int> indices = {open_ref_idx, i};
            if (query(indices) == 1) {
                // f(s_open_ref s_i) == 1 means s_i must be a ')', since s_open_ref is a '('
                ans[i - 1] = ')';
            } else {
                // f(s_open_ref s_i) == 0 means s_i must be a '(', since s_open_ref is a '('
                ans[i - 1] = '(';
            }
        }

        cout << "! ";
        for (char c : ans) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
