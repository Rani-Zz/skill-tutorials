bool comp(const int &a,const int &b)
{
    string A = to_string(a)+to_string(b);
    string B = to_string(b)+to_string(a);
    return A<B;
}
class Solution {
public:
    /**
    *对numbers进行排序sort
    *规则是将两个数转化为string拼接，返回结果小的排序
    *最后依次输出
    *sort()的内部实现还需要了解
    */
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        sort(numbers.begin(),numbers.end(),comp);
        for(int i = 0;i<numbers.size();i++)
        {
            res+=to_string(numbers[i]);
        }
        
        return res;
    }
};