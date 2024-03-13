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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head ;
        ListNode* counter  = head;
        int count = 0 ;
        while(temp!=NULL){
            count++;
            temp = temp-> next ;
        }
        int result = 0;
        while(counter!=NULL){
          result = result +  (counter -> val)*(pow(2, count -1));
          count--;
          counter = counter -> next;
        }
        return result ;
    }
};