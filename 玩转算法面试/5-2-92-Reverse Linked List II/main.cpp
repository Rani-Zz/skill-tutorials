/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head,int n)
    {
        if(head==NULL||head->next==NULL||n<1)
            return head;
        ListNode* tail = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(n--)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        tail->next = cur;
        
        return pre;        
    }
public:
    /**
    *��m��n��λ���ҳ���
    *���շ�ת���������ȥ��
    *ǰһ�����ָ��ת��ĵ�һ����㣬
    *��ת������һ�����Ҫָ��֮���
    */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i=0;i<m-1;i++)
            pre = pre->next;
        ListNode* head2 = pre->next;
        pre->next = reverse(head2,n-m);
        
        ListNode* res = dummy->next;
        delete dummy;
        
        return res;
        
    }
};
