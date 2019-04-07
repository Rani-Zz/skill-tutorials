class Solution {
private:
    bool verify(vector<int> seq,int begin,int end)
    {
        int root = seq[end];
        int i = begin;
        while(seq[i]<root&&i<end)
            i++;
        int j = i;
        while(j<end)
        {
            if(seq[j]<root)
                return false;
            j++;
        }
        bool left = true;
        if(i>begin)
            left  = verify(seq,begin,i-1);
        bool right = true;
        if(j<end)
            right = verify(seq,i,j-1);
        return left&&right;
    }
public:
    /**
    *后序遍历，左右跟 最后一个结点时根节点
    *二叉搜索树 可以根据大小确定左右子树，递归判断左右子树是否符合
    *左小 右大
    */
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return verify(sequence,0,sequence.size()-1);
    }
};