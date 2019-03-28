#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,r = 0;
        int res = 0;
        vector<int> freq(256,0);
        while(r<s.length())
        {
            if(freq[s[r]]==0)
            {  
                freq[s[r++]]++;
            }else
            {
                freq[s[l++]]--;
            }
            
            res = max(res,r-l);
        }
        
        return res;
    }
};
int main(int argc, char** argv) {
	string str = "abcabcbb";
	Solution s;
	int res = s.lengthOfLongestSubstring(str);
	cout<<res;
	
    return 0;
}