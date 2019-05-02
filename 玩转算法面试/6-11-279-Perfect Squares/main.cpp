class Solution {
public:
    /**
    *图的BFS 找n到0的最短路径
    *用queue <n,step>
    *
    */
    int numSquares(int n) {
        if(n==0)
            return 0;
        queue<pair<int,int>> q;
        vector<bool> visited(n+1,false);
        q.push(make_pair(n,0));
        visited[n] = true;
        while(!q.empty())
        {
            int n = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 1;;i++)
            {
                int a = n-i*i;
                if(a<0) break;
                if(a==0)
                    return step+1;
                if(!visited[a])
                {
                    q.push(make_pair(a,step+1));
                    visited[a] = true;
                }
            }
        }
        
        return 0;
    }
};
