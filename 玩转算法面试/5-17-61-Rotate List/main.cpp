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
    *ͳ��������
    *k���������ȵĻ�ʵ����rotate��k%len��λ��
    *len-k%len������ʼ��Ҫrotate��λ��
    *�������������Ū��һ����
    *Ȼ����Ҫrotate�ĵط��Ͽ�
    *headָ��rotate��λ��
    *pָ�����һ����� 
    *���������߼�
    */
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len = 1;
        ListNode* p = head;
        while(p->next!=NULL)
        {
            len++;
            p = p->next;
        }
        
        p->next = head;
        int s = len-k%len;
        for(int i = 0;i<s;i++)
        {
            p = p->next;
        }
        
        head = p->next;
        p->next = NULL;
        
        return head;
    }
};
