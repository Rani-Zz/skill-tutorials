#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int con = 0;
        if(height.empty())
            return con;
        int i = 0,j = height.size()-1;
        while(i<j)
        {
            int h = min(height[i],height[j]);
            con = max(con,h*(j-i));
            while(height[i]<=h&&i<j) i++;
            while(height[j]<=h&&i<j) j--;
        }
        return con;
    }
};
int main(int argc, char** argv) {
	vector<int> nums ={1,8,6,2,5,4,8,3,7};
	Solution s;
	int res = s.maxArea(nums);
	cout<<res;
	
    return 0;
}