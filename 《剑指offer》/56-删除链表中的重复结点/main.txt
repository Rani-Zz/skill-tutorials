/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    /**
    *建一个虚拟头结点
    *pre指向当前结点的前一个结点
    *p指向当前结点 q指向当前结点的下一个结点，判断q与p是否相同，如果相同q继续往后找是否还有相同的结点
    *都找完后pre指向q的下一个，p指向pre的下一个
    *不同的话继续遍历
    */
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        while(p!=NULL)
        {
            if(p->next!=NULL&&p->next->val == p->val)
            {
                ListNode* q = p->next;
                while(q->next!=NULL&&q->next->val==p->val)
                {
                    q = q->next;
                }
                pre->next = q->next;
                p = pre->next;
            }else{
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};