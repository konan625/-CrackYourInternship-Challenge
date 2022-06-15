// Given a string s, the task is to check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	//BRUTE O(n2),O(n)	
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    for(int i=n/2;i>=1;i--){
	        if(n%i==0){string t=s.substr(0,i);
	        string check="";
	        int j=n/i;
	            for(int k=0;k<j;k++){
	                check+=t;
	            }
	            if(check==s) return 1;
	        }
	        
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends