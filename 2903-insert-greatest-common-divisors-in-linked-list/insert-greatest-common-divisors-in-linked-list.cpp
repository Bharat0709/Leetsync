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
    int gcd(int a, int b) {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }

        return result;
    }
    ListNode* insertAtTail(ListNode* tail, int value) {
        ListNode* temp = new ListNode(value);
        tail->next = temp;
        return temp;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* curr = head;
        ListNode* Next = head->next;

        while (Next != NULL) {
            int currValue = curr->val;
            int nextValue = Next -> val;
            int valueToInsert = gcd(currValue, nextValue); 
            ListNode* InsertedNode =  insertAtTail(curr, valueToInsert);
            curr = Next;
            InsertedNode -> next = curr;
            Next = Next->next;
        }
    return head;
    }
};