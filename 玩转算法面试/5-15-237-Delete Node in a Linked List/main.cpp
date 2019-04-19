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
    *只给了要删除的结点
    *所以不能找它的前一个结点
    *只能往后找
    *用后一个结点的值覆盖当前结点，这样结点出现重复
    *转化为删除下一个结点
    */
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
