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
    ListNode* reverse(ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* curr = tail;
        ListNode* temp = tail;
        while (curr != NULL) {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    int pairSum(ListNode* head) {
        if (head->next->next == NULL) {
            return (head->val + head->next->val);
        }
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        ListNode* forward = head;
        ListNode* start = NULL;

        int steps = count / 2;

        while (steps != 0) {
            start = forward;
            forward = forward->next;
            steps--;
        }
        start -> next = reverse(forward);
        ListNode* Next = start -> next;
        ListNode* Temp = head;
        int sum = 0;
        int currSum = 0;
        while (Next != NULL) {
            sum = Temp->val + Next->val;
            if (currSum < sum) {
                currSum = sum;
            }
            Next = Next->next;
            Temp = Temp->next;
        }
        return currSum;
    }
};