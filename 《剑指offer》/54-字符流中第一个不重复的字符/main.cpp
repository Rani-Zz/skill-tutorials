class Solution
{
map<char,int> mp;
queue<char> que;
public:
    /**
    *��map����¼���ֵĴ�
    *�ö��д�ų���һ�ε��ַ������֮ǰû�г��ֹ���������У���β�����
    *�������Ԫ�س��ֳ����Σ����ӣ���֤����Ԫ��Ϊ��һ��ֻ����һ�εĵ��ַ������Ľ��Ϊ����Ԫ��
    */
  //Insert one char from stringstream
    void Insert(char ch)
    {
         mp[ch]++;
        if(mp[ch]==1)
            que.push(ch);
        return;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        
        while(que.size()&&mp[que.front()]>1)
            que.pop();
        if(que.empty())
            return '#';
        return que.front();
        
    }

};