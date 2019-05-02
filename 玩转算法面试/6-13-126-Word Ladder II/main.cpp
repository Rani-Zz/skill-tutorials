class Solution {
private:
    void bfs(const vector<vector<int>>& g, const int& begin,
             const int& end, unordered_map<int,int>& distance)
    {
        queue<int> q;
        q.push(begin);
        distance[begin] = 0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(auto j:g[cur])
            {
                if(distance.find(j)==distance.end())
                {
                    distance[j] = distance[cur]+1;
                    q.push(j);
                }
            }
        }
        return;
    }
    void getRes(vector<vector<int>>& g,int cur,
                int end, unordered_map<int,int>& distance,
                vector<int>& p,vector<vector<string>>& res,
               vector<string>& wordList)
    {
        if(!p.empty()&&p.back()==end)
        {
            res.push_back(getPath(p,wordList));
            return;
        }
        
        for(auto j:g[cur])
        {
            if(distance[j]==distance[cur]+1)
            {
                p.push_back(j);
                getRes(g,j,end,distance,p,res,wordList);
                p.pop_back();
            }
        }
        
        return;
    }
    
    vector<string> getPath(const vector<int>& p,const vector<string>& wordList)
    {
        vector<string> res;
        for(auto e:p)
        {
            res.push_back(wordList[e]);
        }
        
        return res;
    }
    
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
    *建图 g[i]:vector<int>{存放可达的下标} 
    *    i->j 则 j->i
    *广度遍历图：记录距离distance[i]表示开始结点到该节点所走的步数
    *广度遍历的时候遍历了全图
    *最后输出全部结果
    *所以排列组合 
    */
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int end = find(wordList.begin(),wordList.end(),endWord)-wordList.begin();
        
        if(end==wordList.size())
            return res;
        
        int begin = find(wordList.begin(),wordList.end(),beginWord)-wordList.begin();
        if(begin==wordList.size())
            wordList.push_back(beginWord);
        
        int n = wordList.size();
        vector<vector<int>> g(n,vector<int>{});
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(similar(wordList[i],wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        unordered_map<int,int> distance;
        bfs(g,begin,end,distance);
        
        vector<int> p;
        p.push_back(begin);
        getRes(g,begin,end,distance,p,res,wordList);
        
        
        return res;
    }
};
