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
    *preָ��ɷ�ת��һ�ε�ǰһλ
    *curָ��Ҫ��ת��ǰһ�����
    *nextָ��Ҫ��ת�Ľ�� ͷ��ķ�ʽ�ӵ�pre�ĺ���
    *tmp��¼next��next
    *֮��Ҫ��ת����tmp������nextָ��tmp
    *��ת��һ�κ�preָ��cur
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
