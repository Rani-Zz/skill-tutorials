class Solution {
private:
    void reverse(string &str,int m,int n)
    {
        int i = m,j = n;
        while(i<j)
        {
            swap(str[i],str[j]);
            i++;j--;
        }
    }
public:
    /**
    *先reverse整个句子，再reverse每个单词
    */
    string ReverseSentence(string str) {
        if(str.empty())
            return str;
        reverse(str,0,str.size()-1);
        int i = 0,j = 0;
        while(i<str.size())
        {
            j++;
            if(str[j]==' '||j==str.size())
            {
                reverse(str,i,j-1);
                j++;
                i = j;
            }    
        }
        return str;
    }
};