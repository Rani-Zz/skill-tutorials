
class Solution {
private:
    void reverse(string &str,int m,int n)
    {
        for(int i=m,j=n;i<j;i++,j--)
        {
            swap(str[i],str[j]);
        }
    }
public:
    /**
    *[0,...,n-1]×óÒÆKÎ»
    *[0,...,k-1]ÄæÐò [k,...,n-1]ÄæÐò [0,...,n-1]ÄæÐò
    */
    string LeftRotateString(string str, int n) {
        if(str.empty())
            return str;
        if(n==0)
            return str;
        reverse(str,0,n-1);
        reverse(str,n,str.size()-1);
        reverse(str,0,str.size()-1);
        return str;
    }
};