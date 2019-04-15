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
    *保存到栈里面，然后按位相加
    *头插法建立链表
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        stack<int> a;
        stack<int> b;
        while(p!=NULL)
        {
            a.push(p->val);
            p = p->next;
        }
        while(q!=NULL)
        {
            b.push(q->val);
            q = q->next;
        }
        
        
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        int carry = 0;
        
        while(!a.empty()||!b.empty())
        {
            int x = a.empty()? 0:a.top();
            int y = b.empty()? 0: b.top();
            int sum =x+y+carry;
            
            ListNode* s = new ListNode(sum%10);
            s->next = t->next;
            t->next = s;
            carry = sum/10;
            
            if(!a.empty()) a.pop();
            if(!b.empty()) b.pop();
        }
        
        if(carry>0)
        {
            ListNode* s = new ListNode(carry);
            s->next = t->next;
            t->next = s;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
