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
    *²ğÁ´±í
    */
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* q = dummy;
        ListNode* p = head;
        ListNode* pre = head;
        int i = 0;
        while(p!=NULL)
        {
            i++;
            if(i%2==1)
            {
                pre = p;
                p = p->next;
            }else
            {
                q->next = p;
                q = q->next;
                pre->next = p->next;
                p = pre->next;
            }
        }
            q->next = NULL;
            pre->next = dummy->next;
            delete dummy;
            return head;
    }
};
