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
    *建立dummy
    *pre 指向翻转前
    *node1 pre->next node2 pre->next->next
    *
    */
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* pre = dummy;
        while(pre->next!=NULL&&pre->next->next!=NULL)
        {
            ListNode* node1 = pre->next;
            ListNode* node2 = node1->next;
            
            ListNode* tmp = node2->next;
            node2->next = pre->next;
            pre->next = node2;
            node1->next = tmp;
            
            pre = node1;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
