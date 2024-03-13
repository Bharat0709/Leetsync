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
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        ListNode* it=head->next->next;
        ListNode* temp=head->next;
        ListNode* prev=NULL;
        while(it)
        {
            if(it->val==0)
            {
                temp->next=it;
                prev=temp;
                temp=temp->next;
            }
            else
            {
                temp->val+=it->val;
            }
            it=it->next;
        }
        prev->next=NULL;
        return head->next;
    }
};