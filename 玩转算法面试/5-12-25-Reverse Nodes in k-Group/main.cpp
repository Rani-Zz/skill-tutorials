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
    *ͳ���ܵĽڵ���
    *��ת���ȥk��ʣ�µĽ�㻹�ܷ�ת
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) 
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        int count = 0;
        while(p!=NULL)
        {
            count++;
            p = p->next;
        }
        
        while(count>=k)
        {
            ListNode* cur = pre->next;
            ListNode* next = cur->next;
            int t = k-1;
            while(t--)
            {
                ListNode* tmp = next->next;
                next->next = pre->next; //ͷ��
                pre->next = next;
                cur->next = tmp;
                next  = tmp;
            }
            pre = cur;
            count-=k;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
