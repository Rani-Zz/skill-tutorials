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
    *ͳ�ƽ�����
    *�ж�ʣ�����Ƿ�>=k
    *��ת
    *pre ָ��Ҫ��ת��һ�ε�ǰһ�����
    *cur ָ��Ҫ��ת��ǰһ�����
    *next ָ��Ҫ��ת�Ľ��
    *��ת nextͷ�巨��pre tmpָ��next->next curָ��tmp
    *��ת�� pre next cur tmp
    *next = tmp
    *��ת����һ�κ� pre = cur
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
