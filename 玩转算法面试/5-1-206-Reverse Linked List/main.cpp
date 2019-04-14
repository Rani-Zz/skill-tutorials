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
    *pre p next
    */
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pre = NULL;
        ListNode* p = head;
        while(p!=NULL)
        {
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};
