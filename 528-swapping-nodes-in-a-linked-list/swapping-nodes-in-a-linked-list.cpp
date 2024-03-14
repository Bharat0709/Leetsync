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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        int start = k;
        int count = 0;

        ListNode* temp = head;
        while (temp!=NULL){
            count++;
            temp = temp -> next ;
        }

        ListNode* temp1 = head;
        while(start!=1){
            temp1 = temp1 -> next;
            start--;
        }

        ListNode* temp2 = head;
        while((count-k+1)!=1){
            temp2 = temp2 -> next;
            count--;
        }
        int valueStore = temp1 -> val;
        temp1 -> val =  temp2 -> val;
        temp2 -> val = valueStore;

        return head;
    }
};