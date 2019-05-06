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
    *一个一个兼并 时间复杂度O(k*n),k是链表的长度
    *先存到priotiry_queue里面在连接成链表是O(nlogk)
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto list:lists)
        {
            ListNode* p = list;
            while(p!=NULL)
            {
                pq.push(p->val);
                p = p->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(!pq.empty())
        {
           ListNode* s = new ListNode(pq.top());
           p->next = s;
           p = s;
           pq.pop();
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
        
    }
};
