#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0),sv(26,0),res;
        if(s.size()<p.size())
            return res;
        for(int i = 0;i<p.size();i++)
        {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        
        if(pv==sv)
            res.push_back(0);
        
        int l = 0,r = p.size();
        while(r<s.size())
        {
            sv[s[r++]-'a']++;
            sv[s[l++]-'a']--;
            
            if(pv==sv)
                res.push_back(l);
        }
        return res;
    }
    
    
};
int main(int argc, char** argv) {

	Solution s;
	vector<int> res = s.findAnagrams("cbaebabacd","abc");
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	
    return 0;
}