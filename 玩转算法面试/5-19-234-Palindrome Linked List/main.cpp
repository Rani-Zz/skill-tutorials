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
    *快慢指针 中间断开
    *后半部分翻转比较
    */
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        if(head->next==NULL)
            return true;
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
            ListNode* t = p->next;
            p->next = pre;
            pre = p;
            p = t;
        }
        q = head;
        while(pre!=NULL&&q!=NULL)
        {
            if(pre->val!=q->val)
                return false;
            pre = pre->next;
            q = q->next;
        }
        
        return true;
    }
};
