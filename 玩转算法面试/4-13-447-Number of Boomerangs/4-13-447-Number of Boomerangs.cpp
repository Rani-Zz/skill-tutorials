class Solution {
private:
    int dis(pair<int,int> a,pair<int,int> b)
    {
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }
public:
    /**
    *�����㣬����ÿ���㵽�ĵ�ľ��壬ͳ�ƾ�����ͬ�ĵ����
    *�浽map��<���룬����>
    *�ܳ�һ����Ҫ������������������ϵļ��㷽����ɾ��Ǵ�ͬ������ĵ���ѡ����C(n,2)
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
