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
    /**
    *建立dummy
    *合并到L1
    *pre = dummy p = l1 q = l2
    *p q比较
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = l1;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        ListNode* q = l2;
        while(p!=NULL&&q!=NULL)
        {
            if(p->val<q->val)
            {
                pre = p;
                p = p->next;
            }else
            {
                ListNode* s = q->next;
                pre->next = q;
                q->next = p;
                q = s;
                pre = pre->next;                
            }
        }
        if(q!=NULL)
        {
            pre->next = q;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
