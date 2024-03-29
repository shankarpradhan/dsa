//two strings are given that made of a,b and c charcters. 
//find out whether the string s1 converted into s2  using below operation:
// i. the subsequece 'a' and 'c' swap with each other only if 'b' appears in between 'a' and 'c'
// ii. a b c => a b c  

////// observation:
// b never change its position  
// remember when you replace 'a' and 'c', they both are going to place at correct position. it means that the count of 'a' that can be used to replace 'c' is reduced by 1.
// count the number of incorrect positioned 'a' before 'b'.
// swap incorrect positioned 'c' with 'a' only if the count of replace 'c' is more than one


// you don't need swap the characters, it is only for understanding

#include <bits/stdc++.h>
using namespace std;

bool canMake(string s1, string s2){W
    int n = s1.length();
    
    if(s1==s2 || (s1=="abc" && s2=="cba")) return true;
    
    int acnt = 0, bcnt = 0, ccnt = 0;
    
    for(int i  =0; i < n; i++){
        
        if((s1[i]=='b' && s2[i]!='b') || (s2[i]=='b' && s1[i]!='b')){
            return false;
        }
        
        if(s1[i]=='b' || s1[i]!=s2[i]){
            if(s1[i]=='a') acnt++;
            else if(s1[i]=='b') ccnt = acnt;
            else{
                if(ccnt>0){
                    ccnt--;
                    acnt--;
                }   
                else{
                    return false;
                }
            }
        }
        // cout << ccnt << endl;
        
    }
    // if(acnt!=0){
    //     cout << acnt << endl;
    // }
    return true;
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        if(canMake(s1, s2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}
