/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
private:
    void CloneNode(RandomListNode* pHead)
    {
        RandomListNode* p = pHead;
        while(p!=NULL)
        {
            RandomListNode *pClone = new RandomListNode(p->label);
            pClone->next = p->next;
            p->next = pClone;
            p = pClone->next;
        }
    }
    void CloneRandom(RandomListNode* pHead)
    {
        RandomListNode *p = pHead;
        while(p!=NULL)
        {
            RandomListNode *pClone = p->next;
            if(p->random)
            {
                pClone->random = p->random->next;
            }
            p = pClone->next;
        }
    }
    RandomListNode* reconnect(RandomListNode* pHead)
    {
        RandomListNode* newHead = pHead->next;
        RandomListNode* p = pHead;
        while(p!=NULL)
        {
            RandomListNode* pClone = p->next;
            p->next = pClone->next;
            p = p->next;
            if(p!=NULL)
                pClone->next = p->next;
        }
        
        return newHead;
    }
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        //clone node
        CloneNode(pHead);
        
        //clone random
        CloneRandom(pHead);
        //part
        return reconnect(pHead);
    }
};