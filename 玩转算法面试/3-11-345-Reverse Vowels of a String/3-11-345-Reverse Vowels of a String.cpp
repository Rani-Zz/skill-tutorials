#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
*/
class Solution {
private:
    bool isVowels(char c)
    {
        char lower = tolower(c);
        return lower =='a'||lower =='e'||lower =='i'||lower =='o'||lower =='u';
    }
public:
    string reverseVowels(string s) {
        if(s.empty())
            return s;
        int i = 0,j = s.length()-1;
        while(i<j)
        {
            while(i<j&&!isVowels(s[i])) i++;
            while(i<j&&!isVowels(s[j])) j--;
            if(i<j)
            {
                swap(s[i],s[j]);
                i++;j--;
            }
        }
        
        return s;
    }
};
int main(int argc, char** argv) {
	string str = "hello";
	Solution s;
	string res = s.reverseVowels(str);
	cout<<res;
	
    return 0;
}