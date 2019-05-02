class Solution {
private:
    bool similar(const string& s1,const string& s2)
    {
        int diff = 0;
        for(int i = 0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                diff++;
                if(diff>1)
                    return false;
            }
        }
        
        return true;
    }
public:
    /**
    *图的BFS
    *g[i][j] wordList中第i个和第j个是否可达，只相差一个字母即可达
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int end = find(wordList.begin(),wordList.end(),endWord)-wordList.begin();
        if(end==wordList.size())
            return 0;
        int begin = find(wordList.begin(),wordList.end(),beginWord)-wordList.begin();
        if(begin==wordList.size())
            wordList.push_back(beginWord);
        
        int n = wordList.size();
        vector<vector<bool>> g(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
                g[i][j] = g[j][i] = similar(wordList[i],wordList[j]);
        }
        
        vector<int> step(n,0);
        queue<int> q;
        
        q.push(begin);
        step[begin] = 1;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(int i = 0;i<n;i++)
            {
               if(step[i]==0&&g[cur][i])
               {
                   if(i==end)
                       return step[cur]+1;
                   step[i] = step[cur]+1;
                   q.push(i);
               }
            }
        }
        
        return 0;
    }
};
