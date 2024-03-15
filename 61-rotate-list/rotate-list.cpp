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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        int length = count;
        int Equivalentk;
        if (k > count) {
            Equivalentk = k % count;
        } else {
            Equivalentk = k;
        }

        ListNode* curr = NULL;
        ListNode* Next = head;
        while (Equivalentk != 0) {
            while (length != 1) {
                curr = Next;
                Next = Next->next;
                length--;
            }
            Next->next = head;
            curr->next = NULL;
            head = Next;
            curr = NULL;
            Next = head;
            length = count;
            Equivalentk--;
            
        }
        return head;
    }
};