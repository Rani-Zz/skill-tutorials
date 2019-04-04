class Solution
{
map<char,int> mp;
queue<char> que;
public:
    /**
    *用map来记录出现的次
    *用队列存放出现一次的字符，如果之前没有出现过，存入队列，从尾部入队
    *如果队首元素出现超过次，出队，保证队首元素为第一次只出现一次的的字符，最后的结果为队首元素
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