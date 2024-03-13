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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head ;
        ListNode* Next = head -> next;
        head = Next;
        while(Next!=NULL){
            int sum = 0 ;
            while(Next -> val !=0){
                sum = sum + Next->val ;
                Next = Next -> next; 
            }
            curr -> next  -> val = sum;
            curr -> next -> next = Next -> next;
            curr = Next;
            Next = Next -> next;
        }
    return head;
    }
};