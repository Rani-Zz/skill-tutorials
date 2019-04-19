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
    *统计链表长度
    *k大于链表长度的话实际上rotate是k%len的位置
    *len-k%len是链表开始到要rotate的位置
    *遍历链表把链表弄成一个环
    *然后在要rotate的地方断开
    *head指向rotate的位置
    *p指向最后一个结点 
    *真是神仙逻辑
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
