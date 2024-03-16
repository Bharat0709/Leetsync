class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<pair<int, int>> st; 
        int index = 0;
        
        while (head != nullptr) {
            result.push_back(0); 
            while (!st.empty() && st.top().second < head->val) {
                result[st.top().first] = head->val; 
                st.pop();
            }
            st.push({index++, head->val});
            head = head->next;
        }
        
        return result;
    }
};
