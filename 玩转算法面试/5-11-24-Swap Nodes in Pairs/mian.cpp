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
    *p从dummy开始 指向交换前的结点
    *node1 node2交换
    */
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next!=NULL&&p->next->next!=NULL)
        {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            
            p->next = node2;
            node2->next = node1;
            node1->next = next;
            
            p = node1;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
