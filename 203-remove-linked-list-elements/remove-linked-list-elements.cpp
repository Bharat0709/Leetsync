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
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL || (head->next == NULL && head->val != val)) {
            return head;
        }

        if (head->next == NULL && head->val == val) {
            return NULL;
        }
        ListNode* curr = head;
        ListNode* Next = head->next;

        while (Next != NULL) {
            if (curr->val == val) {
                curr->next = NULL;
                curr = Next;
                Next = Next->next;
                if (curr->next == NULL && curr->val == val) {
                    return NULL;
                }
                head = curr ;
            } else if (Next->val == val) {
                Next = Next->next;
                curr->next->next = NULL;
                curr->next = Next;
            } else {
                curr = Next;
                Next = Next->next;
            }
        }
        return head;
    }
};