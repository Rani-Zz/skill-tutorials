#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int i = 0,j = s.length()-1;
        while(i<j)
        {
           while(i<j&&!isalnum(s[i])) i++;
           while(i<j&&!isalnum(s[j])) j--;
            if(i<j)
            {
                if(tolower(s[i])!=tolower(s[j]))
                    return false;
                 i++;
                 j--;
            }
           
        }
        
        return true;
    }
};
int main(int argc, char** argv) {
	string str = "A man, a plan, a canal: Panama";
	Solution s;
	cout<<s.isPalindrome(str);
	
    return 0;
}