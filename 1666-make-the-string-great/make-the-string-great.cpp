#include<stack>;
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        if (s.length() == 1) {
            return s;
        } else {
            st.push(s[0]);
        }

        for (int i = 1; i < s.length(); i++) {
            if (!st.empty() && (st.top() - s[i] == 32 || st.top() - s[i] == -32 )) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string ans;

        while (!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }

        return ans;
    }
};