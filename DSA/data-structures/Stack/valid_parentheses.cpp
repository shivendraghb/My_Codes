#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.size() == 0) return false;

                if((st.top() == '(' && s[i] == ')') ||
                   (st.top() == '{' && s[i] == '}') ||
                   (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution sol;
    string testCases[] = {"()", "()[]{}", "(]", "([])"};

    for (const string& test : testCases) {
        cout << "Input: " << test
             << " => Output: " << (sol.isValid(test) ? "true" : "false")
             << endl;
    }

    return 0;
}
