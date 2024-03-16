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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast1 = head;
        ListNode* fast2 = head->next;
        ListNode* temp = fast2;
        while (fast2 != NULL) {
            fast1->next = fast2->next;
            if (fast2->next == NULL) {
                fast1->next = temp;
                return head;
            } else {
                fast1 = fast2->next;
            }
            fast2->next = fast1->next;
            fast2 = fast1->next;
        }
        fast1->next = temp;
        return head;
    }
};