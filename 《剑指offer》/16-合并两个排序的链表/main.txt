/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = pHead1;
        ListNode* pre = dummy;
        ListNode *p1 = pHead1,*p2 = pHead2;
        ListNode *s;
        while(p1&&p2)
        {
            if(p1->val<p2->val)
            {
                pre = p1;
                p1 = p1->next; 
            }else{
                s = p2->next;
                pre->next = p2;
                p2->next = p1;
                p2 = s;
                pre = pre->next;
            }
        }
        if(p2)
            pre->next = p2;
        return dummy->next;
    }
};