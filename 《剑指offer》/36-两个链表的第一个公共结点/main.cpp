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
    /**
    *让两个链表长度相等时再逐个比较，找到第一个相同的结点
    *先统计两个链表的长度，让长的链表先走
    */
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL)
            return NULL;
        int l1 = 0,l2 = 0;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1!=NULL)
        {
            l1++;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            l2++;
            p2 = p2->next;
        }
        int diff = 0;
        if(l1>l2)
        {
            diff = l1-l2;
            p1 = pHead1;
            p2 = pHead2;
        }else{
            diff = l2-l1;
            p1 = pHead2;
            p2 = pHead1;
        }
        
        while(diff>0)
        {
            p1 = p1->next;
            diff--; 
        }
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1==p2)
                break;
            p1 = p1->next;
            p2 = p2->next;          
        } 
        return p1;
    }
};