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
        ListNode* temp = head;
        ListNode* Next = head;
        while (Next != NULL) {
            Next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = Next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        if (head == NULL) {
            return false;
        }

        if (head->next == NULL) {
            return true;
        }

        ListNode* Temp = head;

        int count = 0;
        while (Temp != NULL) {
            count++;
            Temp = Temp->next;
        }

        int counter = count / 2 + count % 2;
        ListNode* temp = head;
        ListNode* curr = NULL;
        while (counter != 0) {
            curr = temp;
            temp = temp->next;
            counter--;
        }
        curr->next = reverse(temp);
        curr = curr->next;
        ListNode* forward = head;
        while (curr != NULL) {
            if (curr->val == forward->val) {
                curr = curr->next;
                forward = forward->next;
            } else {
                return false;
            }
        }
        return true;
    }
};