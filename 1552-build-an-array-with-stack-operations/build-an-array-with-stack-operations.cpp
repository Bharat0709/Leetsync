class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> result;
        int size = target.size();
        int targetIndex = 0;

        for (int i = 1; i <= n && targetIndex < size; i++) {
            int currTarget = target[targetIndex];
            st.push(i);
            result.push_back("Push");
            if (st.top() != currTarget) {
                st.pop();
                result.push_back("Pop");
            } else {
                targetIndex++;
            }
        }
        return result;
    }
};