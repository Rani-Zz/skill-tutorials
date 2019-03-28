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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        ListNode* next;
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};