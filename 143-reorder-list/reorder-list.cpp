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
    void insertAtTail(ListNode*& tail, int val) {
        ListNode* temp = new ListNode(val);
        tail->next = temp;
        tail = temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        while (curr != NULL) {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (head->next != NULL) {
            ListNode* tail = new ListNode(head->val);
            ListNode* NewHead = tail;
            ListNode* insert = head->next;
            int count = 1;

            while (insert != NULL) {
                count++;
                insertAtTail(tail, insert->val);
                insert = insert->next;
            }

            ListNode* reversed = reverse(NewHead);

            ListNode* curr = head;
            ListNode* Dcurr = reversed;
            ListNode* temp = curr->next;
            ListNode* Dtemp = reversed->next;

            while (count != 1) {
                if (count != 1) {
                    curr->next = Dcurr;
                    count--;
                } else if(count == 1){
                    curr -> next = NULL;
                    return;
                }
                if (count != 1) {
                    Dcurr->next = temp;
                    count--;
                } else if (count == 1) {
                    Dcurr->next = NULL;
                    return;
                }
                curr = temp;
                Dcurr = Dtemp;
                temp = temp->next;
                Dtemp = Dtemp->next;
                cout << count << endl;
            }
            curr->next = NULL;
        }
    }
};