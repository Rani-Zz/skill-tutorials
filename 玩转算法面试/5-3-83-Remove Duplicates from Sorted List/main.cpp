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
    *±éÀúÉ¾³ı
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* p = head;
        while(p->next!=NULL)
        {
            if(p->next->val==p->val)
            {
                ListNode* q = p->next;
                p->next = q->next;
            }else 
                p = p->next;
        }
        
        return head;
        
    }
};
