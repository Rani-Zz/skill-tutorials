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
    *������������Ҹ� ���һ�����ʱ���ڵ�
    *���������� ���Ը��ݴ�Сȷ�������������ݹ��ж����������Ƿ����
    *��С �Ҵ�
    */
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return verify(sequence,0,sequence.size()-1);
    }
};