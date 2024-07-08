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

        ListNode* curr = head;
        ListNode *forw=curr;
        ListNode* newHead=curr;
        while (forw && forw->next) {
            forw = curr->next;
            int sum = 0;
            if (curr->val == 0) {
                while (forw->val != 0) {
                    sum += forw->val;
                    forw = forw->next;
                }
                curr->val=sum;
                if(forw->next!=NULL)
                    curr->next=forw;
                else
                    curr->next=NULL;
                curr=forw;
            }
        }
        return newHead;
    }
};