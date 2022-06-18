Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        if(n==0) return 0;
        int ans1=INT_MIN;//INT_MIN instead of 0 takes care of fact that 3 cant be cut into segments [5,2,2] 3-2=1 , which cant be cut;
        int ans2=INT_MIN;//to understand us test case n=7, x=5, y=5, z=2
        int ans3=INT_MIN;
        if(x<=n) ans1=1+maximizeTheCuts(n-x,x,y,z);
        if(y<=n) ans1=1+maximizeTheCuts(n-y,x,y,z);
        if(z<=n) ans1=1+maximizeTheCuts(n-z,x,y,z);
        return max(ans1,max(ans2,ans3));
    }
};

//Memo
    //Function to find the maximum number of cuts.
    int helper(int n, int x, int y, int z,vector<int>& t){
        if(n==0) return 0;
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        int ans3=INT_MIN;
        if(t[n]!=-1) return t[n];
        if(x<=n) ans1=1+maximizeTheCuts(n-x,x,y,z);
        if(y<=n) ans2=1+maximizeTheCuts(n-y,x,y,z);
        if(z<=n) ans3=1+maximizeTheCuts(n-z,x,y,z);
        return t[n]=max(ans1,max(ans2,ans3));
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> t(n+1,-1);
        return helper(n,x,y,z,t);        
    }

//Tabulisation
 int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int ans1=INT_MIN;
            int ans2=INT_MIN;
            int ans3=INT_MIN;
            if(x<=i){
                ans1=1+dp[i-x];
            }
            if(y<=i){
                ans2=1+dp[i-y];
            }
            if(z<=i){
                ans3=1+dp[i-z];
            }
            dp[i]=max(ans1,max(ans2,ans3));
        }
        if(dp[n]<0) return 0;
        return dp[n];
        
    }
