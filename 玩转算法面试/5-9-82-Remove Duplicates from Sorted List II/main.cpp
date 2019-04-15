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
    *����dummy
    *�ҵ�������ͬ��
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        while(p!=NULL)
        {
            if(p->next!=NULL&&p->next->val==p->val)
            {
                ListNode* q = p->next;
                while(q->next!=NULL&&q->next->val==q->val)
                    q =  q->next;
                pre->next = q->next;
                p = pre->next;
            }else
            {
                pre = p;
                p =p->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
