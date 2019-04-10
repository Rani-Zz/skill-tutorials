#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c:t)
            map[c]++;
        int l=0,r=0,len = s.size()+1,head=0,count=t.size();
        while(r<s.size())
        {
            if(map[s[r]]>0) count--;
            map[s[r++]]--;//½ø
            while(count==0)
            {
                if(r-l<len)
                {
                    len = r-l;
                    head = l;
                }
                
                if(map[s[l]]==0)
                    count++;
                map[s[l++]]++;//³ö
            }
        }
        return len==s.size()+1?"":s.substr(head,len);
    }
};
int main(int argc, char** argv) {

	Solution s;
	string res = s.minWindow("ADOBECODEBANC","ABC");
	cout<<res;

    return 0;
}