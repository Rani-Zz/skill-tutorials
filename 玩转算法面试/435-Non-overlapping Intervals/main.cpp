/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &a,const Interval &b)
{
    if(a.end!=b.end)
        return a.end<b.end;
    return a.start<b.start;
}
class Solution {
public:
    /**
    动态规划：问题转化为最多保留多少个 最长子序列问题 为方便比较先排序
    贪心算法：end越小，留给后面的空间越多，越贪心
    */
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;

        sort(intervals.begin(),intervals.end(),compare);
        int res = 1;
        int pre = 0;
        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i].start>=intervals[pre].end)
            {
                res++;
                pre = i;
            } 
        }
        
        return intervals.size()-res;
    }
};