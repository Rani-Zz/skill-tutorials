/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ArrayList;
        if(head==NULL)
            return ArrayList;
        stack<int> s;
        ListNode* p = head;
        while(p!=NULL)
        {
            s.push(p->val);
            p = p->next;
        }
        
        while(!s.empty())
        {
            ArrayList.push_back(s.top());
            s.pop();
        }
        return ArrayList;
    }
};