// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
          if(s1.length() != s2.length()) return ("No");
       int n = s1.length();
       
       int i = 0, j = 0;
       while(i < n && j < n){
           while(s1[i] == '#') i++;
           while(s2[j] == '#') j++;
           if(s1[i] != s2[j]) return ("No");
           if(s1[i] == 'B' && j < i) return ("No");
           if(s1[i] == 'A' && j > i) return ("No");
           i++,j++;
       }
       
       return ("Yes");
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends