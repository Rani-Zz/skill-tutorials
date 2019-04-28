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
    *�������Ͽ�
    *p�� q��
    *����Ͽ���תȻ������
    */
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return ;
        ListNode* p = head;
        ListNode* q = head;
        while(p->next&&p->next->next)
        {
            p = p->next->next;
            q = q->next;
        }
        
        p = q->next;
        q->next = NULL;
        
        ListNode* pre = NULL;
        while(p!=NULL)
        {
            ListNode* s = p->next;
            p->next = pre;
            pre = p;
            p = s;
        }
        
        p = head;
        while(p!=NULL&&pre!=NULL)
        {
            ListNode* t = pre->next;
            pre->next = p->next;
            p->next = pre;
            p = p->next->next;
            pre = t;
        }
        
        return ;
    }
};
