There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
//Recursion
class Solution {
public:
    int mod=1e9+7;
    int helper(int m,int n ,int maxmove,int move,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(move==maxmove) return 0;
        int ways=0;
        ways=ways+helper(m,n,maxmove,move+1,i+1,j) % mod;
        ways=ways+helper(m,n,maxmove,move+1,i-1,j) % mod;
        ways=ways+helper(m,n,maxmove,move+1,i,j+1) % mod;
        ways=ways+helper(m,n,maxmove,move+1,i,j-1) % mod;
        return ways % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return helper(m,n,maxMove,0,startRow,startColumn);
        
    }
};

//memoization
class Solution {
public:
    int mod=1e9+7;
    int helper(int m,int n ,int maxmove,int move,int i,int j,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(move==maxmove) return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        int ways=0;
        ways=(ways+helper(m,n,maxmove,move+1,i+1,j,dp) % mod)%mod;
        ways=(ways+helper(m,n,maxmove,move+1,i-1,j,dp) % mod)%mod;
        ways=(ways+helper(m,n,maxmove,move+1,i,j+1,dp) % mod)%mod;
        ways=(ways+helper(m,n,maxmove,move+1,i,j-1,dp) % mod)%mod;
        dp[i][j][move]=ways % mod;
        return dp[i][j][move]%mod;
    }
    int findPaths(int m, int n, int M, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(M+1,-1)));
        return helper(m,n,M,0,startRow,startColumn,dp); 
    }
};