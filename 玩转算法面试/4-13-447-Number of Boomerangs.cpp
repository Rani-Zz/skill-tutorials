class Solution {
private:
    int dis(pair<int,int> a,pair<int,int> b)
    {
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }
public:
    /**
    *遍历点，计算每个点到改点的具体，统计距离相同的点个数
    *存到map中<距离，个数>
    *总成一组需要三个点所以用排列组合的计算方法组成就是从同样距离的点钟选两个C(n,2)
    */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        if(points.empty())
            return res;
        for(int i = 0;i<points.size();i++)
        {
            unordered_map<int,int> map;
            for(int j = 0;j<points.size();j++)
            {
                if(i==j) continue;
                int len = dis(points[i],points[j]);
                map[len]++;  
            }
            for(auto m:map)
                res+=m.second*(m.second-1);
        }
        return res;
    }
};
