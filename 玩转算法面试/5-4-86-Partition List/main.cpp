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
    *把小于x的结点拆出来
    */
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        ListNode* dummy2 = new ListNode(-1);
        ListNode* q = dummy2;
        while(p!=NULL)
        {
            if(p->val<x)
            {
                ListNode *s = p;
                q->next = s;
                q = q->next;
                
                pre->next = s->next;
                p = pre->next;
            }else
            {
                pre = p;
                p = p->next;
            }
        }
        
        q->next = dummy->next;
        ListNode *res = dummy2->next;
        delete dummy;
        delete dummy2;
        
        return res;
    }
};
