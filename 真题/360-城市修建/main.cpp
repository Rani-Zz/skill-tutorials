#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long minX = INT_MAX;
        long long minY = INT_MAX;
        long long maxX = INT_MIN;
        long long maxY = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            long long x,y;
            cin>>x>>y;
            minX = min(minX,x);
            minY = min(minY,y);
            maxX = max(maxX,x);
            maxY = max(maxY,y);
        }
        long long l = max(maxX-minX,maxY-minY);
        cout<< l*l<<endl;
    }
    return 0;
}
}