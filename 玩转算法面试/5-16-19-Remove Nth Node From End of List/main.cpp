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
    *先找到倒数第n个结点
    *再删除
    *所以需要记录前一个结点
    *建立dummy
    *pre p q
    *k
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* q = head;
        int k  = 0;
        while(q!=NULL)
        {
            q = q->next;
            k++;
            if(k>n)
            {
                pre = p;
                p = p->next;
            }
        }
        
        pre->next = p->next;
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
