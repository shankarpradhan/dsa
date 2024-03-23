// Q. Given an array of integers and max_moves, you need to choose an integer x and do some operation using x. In each operation, you must decrease any element of the array by x. The goal is to make all the 
// elements of the array non-posive or equal to zero (<= 0).

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll(n) vector<long long> arr(n)
#define vi(n,m) vector<int> arr(n,m)
#define vm(n,m) vector<vector<int>> arr(n+1, vector<int>(m+1,0))
#define umi unordered_map<int,int>mp
#define vin(n) for(int i = 1; i <= n; i++)

bool makeNonPositive(vector<int> a, int m, int x){
    int moves = 0, n = a.size();
    for(int i = 1; i < n; i++){
        moves += ((a[i]/x) + (a[i]%x != 0));
        // cout << a[i] << " "<< moves << endl;
    }


    if(moves > m){
        return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    vi(n+1, 0);

    vin(n){
        cin >> arr[i];
    }

    int s= 1, e = 1000000000;

   
    while(s<=e){
        int mid = s+(e-s)/2;

        if(makeNonPositive(arr, m, mid)){
            e = mid-1;
        }
        else{
            s = mid+1;
        }

    }

    cout << s << endl;
    return 0;
}
