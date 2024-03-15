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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* currL1 = list1;
        ListNode* tempL1 = list1;
        ListNode* currL2 = list2;
        ListNode* tempL2 = list2;

        while (a!=1) {
            currL1 = currL1->next;
            a--;
        }

        while (b!=0) {
            tempL1 = tempL1->next;
            b--;
        }

        while (tempL2->next != NULL) {
            tempL2 = tempL2->next;
        }
        currL1->next = currL2;
        tempL2->next = tempL1->next;
        return list1;
    }
};