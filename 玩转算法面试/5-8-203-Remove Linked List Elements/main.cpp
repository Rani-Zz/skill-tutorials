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
    *½¨Á¢dummy
    *±éÀú pre
    */
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        while(p!=NULL)
        {
            if(p->val==val)
            {
                pre->next = p->next;
                p = pre->next;
            }else
            {
                pre = p;
                p = pre->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
