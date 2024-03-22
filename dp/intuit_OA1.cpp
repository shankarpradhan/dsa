// Understanding :- You are given a Matrix of size NXM; your task is to start your journey from any cell you want and end your journey at any cell you want :) 
// You are only allowed to jump in the right or down direction. 

// Cost of journey := Total sum of adjacent elements selected. 


// x—-->y = y - x. 

// Deep ocean :- Let's consider a case where you jump from x1 to x2; x2 to x3; x3 to x4 and x4 to x5 

// Sum = (x2-x1) + (x3-x2) + (x4-x3) + (x5-x4) = x5 - x1 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll(n) vector<long long> arr(n)
#define vi(n) vector<int> arr(n)
#define vm(n,m) vector<vector<int>> arr(n+1, vector<int>(m+1,0))
#define umi unordered_map<int,int>mp
#define vin(n) for(int i = 0; i < n; i++)



int main(){
    int n,m;
    cin >> n >> m;
    vm(n,m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    int maxxi = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int minni = min(dp[i][j-1], dp[i-1][j]);
            maxxi = max(maxxi, arr[i][j]-minni);
            dp[i][j] = min(arr[i][j], minni);
        }
    }

    cout << maxxi << endl;
    return 0;
}
