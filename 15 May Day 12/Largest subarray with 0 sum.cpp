// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> m;
        int currsum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            currsum+=A[i];
            if(currsum==0){
                maxi=i+1;
            }
            else{
                if(m.find(currsum)!=m.end()){
                    maxi=max(maxi,i-m[currsum]);
                }
                else{
                    m[currsum]=i;
                }
            }
        }
        return maxi;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends