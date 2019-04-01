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
    *找到环中的结点：快慢指针，相遇时的结点一定在环中
    *找到环的入口：快p2 走了2x，慢p1走了x，快指针比慢指针多走了一圈，所以2x-x = n，x = n
    *           所以p1恰好走了环的节点数，p2回到头部，两个指针同步走，相遇时即入口结点
    *设起点到相遇点距离为x，起点到入口点距离为y，环长度为r，
    *则快慢针相遇时，满足2x-x=nr，n为快针在环中转的圈数。--> x=nr
    *快慢针相遇点距环入口点距离x-y
    *相遇后，快针从起点重新开始以步长为1速度开始走，
    *经过距离y到达环入口点，慢针走y步后距离环入口点距离为x-y+y=x=nr，
    *即走到了环入口点，两个指针相遇
    */
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while(p1!=NULL&&p2!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1==p2)
            {
                p2 = pHead;
                while(p1!=p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                if(p1==p2)
                    return p1;
            }
        }
        return NULL;
    }
};