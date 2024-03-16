class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<pair<int, int>> st; // Pair of (index, value)
        int index = 0;
        
        while (head != nullptr) {
            result.push_back(0); // Initialize result for current node
            while (!st.empty() && st.top().second < head->val) {
                result[st.top().first] = head->val; // Update result for indices where the value is smaller
                st.pop();
            }
            st.push({index++, head->val}); // Push current value and its index
            head = head->next;
        }
        
        return result;
    }
};
