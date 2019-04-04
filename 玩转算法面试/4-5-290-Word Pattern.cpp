class Solution {
public:
    /**
    *�ȿ����������������Ϊtrue,��һ��Ϊ��Ϊfalse
    *ƥ��ɹ�������:��ͬ���ַ����ֵĴ���һ�£���λ��Ҳһ��
    *str�пո��������ַ����룬ÿ�ζ���һ�����ַ�û�ж��굫��str�Ѿ�������false
    *ĳ���ַ���ƥ�� false
    *��unordered_map��ţ���Ϊ����Ҫ��֤λ��Ҳһ�£�����map�����ŵĲ���ֻ�ǳ��ֵĴ���
    *����aba�� "dag cat cat"����
    *�����߼�����±�i+1���Խ���������
    */
    bool wordPattern(string pattern, string str) {
        if(pattern.empty()&&str.empty())
            return true;
        if(pattern.empty()||str.empty())
            return false;
        int i = 0;
        unordered_map<char,int> pmap;
        unordered_map<string,int> smap;
        istringstream in(str);
        string buf;
        for(i;in>>buf;i++)
        {
            if(i==pattern.size()||pmap[pattern[i]]!=smap[buf])
                return false;
            pmap[pattern[i]] = smap[buf] = i+1;
        }
        
        return i==pattern.size();
    }
};