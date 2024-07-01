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

        ListNode* newHead = head->next; // New head will be the second node
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            ListNode* nextPair = curr->next->next; // The start of the next pair
            ListNode* second = curr->next;

            // Swap the pair
            second->next = curr;
            curr->next = nextPair;

            // Connect previous pair with the current swapped pair
            if (prev != NULL) {
                prev->next = second;
            }

            // Move to the next pair
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};
