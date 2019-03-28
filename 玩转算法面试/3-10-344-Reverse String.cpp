#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty())
            return;
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;j--;
        }
        return;
    }
};
int main(int argc, char** argv) {
	vector<char> str = {'h','e','l','l','o'};
	Solution s;
	s.reverseString(str);
	for(auto c: str)
	  cout<<c<<" ";
	
    return 0;
}