class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        if (s.length() == 1) {
            return 1;
        } else {
            st.push(s[0]);
        }
        for (int i = 1; i < s.length(); i++) {
            if (!st.empty() && ((st.top() == 'A' && s[i] == 'B') ||
                (st.top() == 'C' && s[i] == 'D'))) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        int ans = 0 ; 

        while(!st.empty()){
            ans++;
           st.pop();
        }
        return ans;
    }
};