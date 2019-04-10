class Solution {
public:
    /**
    *���ϵ������¼ӣ���������һ�еĽ����ѡ����С�ľ���
    *Ҫ���Ľ����С�����������ӽṹ��ÿһ����ѡ����Ԫ������С���ĸ���
    *����ע��t[i][0]���ڵ�Ԫ��ֻ��һ��t[i-1][0]
    *t[i][i]���ڵ�Ҳֻ��һ��t[i-1][i-1]
    *����t[i][j] +=min(t[i-1][j],t[i-1][j-1])
    *����Ҫ��������飬��ԭ������ֱ�ӼӾͿ�����
    */
    int minimumTotal(vector<vector<int>>& triangle) {

        if(triangle.empty())
            return 0;
        int n = triangle.size();
        for(int i =1;i<n;i++)
        {
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][i]+=triangle[i-1][i-1];
            for(int j = 1;j<i;j++)
                triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
        }
        
        int res = INT_MAX;
        for(int i = 0;i<n;i++)
            res = min(res,triangle[n-1][i]);
        return res;
    }
};
