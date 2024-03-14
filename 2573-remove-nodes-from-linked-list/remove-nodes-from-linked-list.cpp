/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while (curr != NULL) {
            Next = Next->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        stack<int> st;
        st.push(0);
        ListNode* reversed = reverse(head);
        ListNode* curr = reversed;
        ListNode* temp = reversed->next;
        while (temp != NULL) {
            if (curr->val >= temp->val && curr->val >= st.top() ||
                (temp->val >= curr->val && curr->val >= st.top())) {
                st.push(curr->val);
            }
            temp = temp->next;
            curr = curr->next;
        }
        ListNode* InitialList = reverse(reversed);
        ListNode* NewTemp = InitialList;
        ListNode* Prev = NULL;

        while (NewTemp != NULL) {
            if (!st.empty() && NewTemp->val != st.top() && st.top() != 0) {
                if (NewTemp == InitialList) {
                    InitialList = NewTemp->next;
                    NewTemp->next = NULL;
                    NewTemp = InitialList;
                } else {
                    Prev->next = NewTemp->next;
                    NewTemp->next = NULL;
                    NewTemp = Prev->next;
                }
            } else {
                if (!st.empty()) {
                    st.pop();
                }
                Prev = NewTemp;
                NewTemp = NewTemp->next;
            }
        }
        return InitialList;
    }
};