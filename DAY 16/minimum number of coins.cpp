//recursion
int minCoins(int coins[], int M, int V) 
	{ 
	    // base case
	   if(M==0) return INT_MAX-1;
	   if(V==0) return 0;
	   if(coins[M-1]<=V){
	       return min(1+minCoins(coins,M,V-coins[M-1]),minCoins(coins,M-1,V));
	   }
	   else{
	       return minCoins(coins,M-1,V);
	   }
    }

Tabulisation
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>> dp(M+1,vector<int>(V+1,INT_MAX-1));//here we have used INT_MAX-1 to avoid integer overflow at the step 1+dp[i][j-coins[i-1]]
	   for(int i=0;i<=M;i++) dp[i][0]=0;
	   for(int i=1;i<=M;i++){
	       for(int j=1;j<=V;j++){
	           if(coins[i-1]<=j){
	               dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	           }
	           else{
	               dp[i][j]=dp[i-1][j];
	           }
	       }
	   }
       //for the cases where the amount doesnt has coins that divide it as a whole...coin cant be 2.5
       //example arr = [3] , sum = 4
	   if(dp[M][V]>=1e6+1) return -1;
	   return dp[M][V];
	} 
