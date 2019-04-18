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
    *统计结点个数
    *判断剩余结点是否>=k
    *翻转
    *pre 指向要翻转的一段的前一个结点
    *cur 指向要翻转的前一个结点
    *next 指向要翻转的结点
    *翻转 next头插法到pre tmp指向next->next cur指向tmp
    *翻转后 pre next cur tmp
    *next = tmp
    *翻转玩完一段后 pre = cur
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1)
            return head;
        ListNode* p = head;
        int count = 0;
        while(p!=NULL)
        {
            count++;
            p = p->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        
        while(count>=k)
        {
            ListNode* cur = pre->next;
            ListNode* next = cur->next;
            int t = k-1;
            while(t--)
            {
                ListNode* tmp = next->next;
                next->next = pre->next;
                pre->next = next;
                
                cur->next = tmp;
                next = tmp;
            }
            pre = cur;
            count-=k;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
