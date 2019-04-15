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
    *遍历链表 按位相加
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        int carry = 0;
        while(p!=NULL||q!=NULL)
        {
            int x = p==NULL? 0: p->val;
            int y = q==NULL? 0: q->val;
            int sum = x+y+carry;
            
            ListNode* s = new ListNode(sum%10);
            carry = sum/10;
            t->next = s;
            t = t->next;
            if(p!=NULL) p = p->next;
            if(q!=NULL) q = q->next;
        }
        if(carry>0)
        {
            ListNode* s = new ListNode(carry);
            t->next = s;
            t = t->next;
        }
        ListNode* res = dummy->next;
        return res;
    }
};
