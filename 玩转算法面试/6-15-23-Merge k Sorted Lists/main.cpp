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
    *һ��һ���沢 ʱ�临�Ӷ�O(k*n),k������ĳ���
    *�ȴ浽priotiry_queue���������ӳ�������O(nlogk)
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
