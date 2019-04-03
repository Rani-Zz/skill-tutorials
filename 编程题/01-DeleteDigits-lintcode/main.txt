/**
 * lintcode-182
 * 给出一个字符串 A，表示一个 N 位正整数，删除其中 k 位数字，
 * 使得剩余的数字仍然按照原来的顺序排列产生一个新的正整数。
 * 找到删除 k 个数字之后的最小正整数。N <= 240，k <= N。
 * 987132 4
 * 1000230 5
*/
class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     * 当某一位比后一位大时删除
     * 最后的结果如果前面是0要去掉
     */
    string DeleteDigits(string &A, int k) {
        // write your code 
        string res;
        if(A.empty())
			return res;
		res = A;
		while(k)
		{
			int i = 0;
			while(i<res.length()-1&&res[i]<=res[i+1])
				i++;
			res = res.substr(0,i)+res.substr(i+1);
			k--;
		}
		
		int i = 0;
		while(res[i]=='0')
		    i++;
		 res = res.substr(i);
		return res;  
    }
};