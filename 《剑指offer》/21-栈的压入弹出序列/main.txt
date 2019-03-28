class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty())
            return false;
        vector<int> tmp;//辅助数组按入栈顺序入栈，入栈后看是可出栈
        for(int i=0,j=0;i<pushV.size();i++)
        {
            tmp.push_back(pushV[i]);
            while(tmp.back()==popV[j]&&j<popV.size())
            {
                tmp.pop_back();
                j++;
            }
        }
        return tmp.empty();
    }
};