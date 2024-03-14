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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (head->next->next == NULL) {
            ListNode* Temp = head;
            head->next->next = Temp;
            head = head->next;
            Temp->next = NULL;
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* temp = head->next->next;
        ListNode* PrePrev = NULL;
        head = head->next;

        while (curr != NULL) {
            cout << "CURR" << curr->val << endl;
            cout << "PREV " << prev->val << endl;
            curr->next = prev;
            prev->next = temp;
            if (PrePrev != NULL) {
                PrePrev->next = curr;
                cout << "PP " << PrePrev->val;
            }
            PrePrev = prev;
            prev = temp;
            if (temp == NULL) {
                return head;
            }else if( temp -> next == NULL){
                return head;
            }else{
                curr = temp->next;
                temp = temp->next->next;
            }
        }
        return head;
    }
};