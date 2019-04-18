/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p = head;
        ListNode* dummy = new ListNode(-1);
        while(p!=NULL)
        {
            ListNode* pre = dummy;
            ListNode* q = dummy->next;
            while(q!=NULL&&q->val<p->val)
            {
                pre = q;
                q = q->next;
            }
            ListNode* s = p->next;
            p->next = q;
            pre->next = p;
            p = s;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
