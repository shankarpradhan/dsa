//Chef knows the projected sales of his store for the next n days. The projected sales in ith day A[i] sales. 
//On any particular day, Chef can announce that his shop is closing which will double his sales for that day, 
//but since Chef is a man of his word, he won't make any sale after that day.
//Find the maximum possible total sales which Chef can make.

// find maxsum possible till ith day, if we consider ith day is our last day of sale.
// i is our last day:    maxsum = sum(0....i-1)+currentday*2
// try for every index 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        
        long long maxxi = 0, sum=0;
        while(n--){
            int v;
            cin >> v;
            
            maxxi = max(maxxi, v*2+sum);
            
            sum += v;
        }
        
        cout << maxxi << endl;
    }

    return 0;
}
