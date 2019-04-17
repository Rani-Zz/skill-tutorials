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
    *pre指向可翻转的一段的前一位
    *cur指向要翻转的前一个结点
    *next指向要翻转的结点 头插的方式加到pre的后面
    *tmp记录next的next
    *之后要翻转的是tmp，所以next指向tmp
    *翻转完一段后pre指向cur
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        int count = 0;
        while(p!=NULL)
        {
            p = p->next;
            count++;
        }
        
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
