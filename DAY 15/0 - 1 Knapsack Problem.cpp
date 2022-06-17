//Recursion
int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0 || W==0){
           return 0;
       }
       if(wt[n-1]<=W){
           return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       }
       else{
           return knapSack(W,wt,val,n-1);
       }
       
    }

//Memoization
int helper(int W, int wt[], int val[], int n,vector<vector<int>>& t) 
    { 
       // Your code here
       if(n==0 || W==0){
           return 0;
       }
       if(t[n][W]!=-1) return t[n][W];
       if(wt[n-1]<=W){
           return t[n][W]=max(val[n-1]+helper(W-wt[n-1],wt,val,n-1,t),helper(W,wt,val,n-1,t));
       }
       else{
           return t[n][W]=helper(W,wt,val,n-1,t);
       }
       
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0 || W==0){
           return 0;
       }
       vector<vector<int>> t(n+1,vector<int> (W+1,-1));
       return helper(W,wt,val,n,t);
       
    }

//TAbulation
int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int> (W+1,0));
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(wt[i-1]<=j){
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }
               else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }