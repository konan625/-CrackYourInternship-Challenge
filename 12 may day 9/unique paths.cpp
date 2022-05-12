class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=1;i<m+1;i++){
            dp[i][1]=1;
        }
        for(int i=1;i<n+1;i++){
            dp[1][i]=1;
        }
        for(int i=2;i<m+1;i++){
            for(int j=2;j<n+1;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m][n];
        
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        int c=m-1;
        int total=m+n-2;
        double ans=1;
        for(int i=1;i<=c;i++){
            ans= ans * (total - c + i) / i;
        }
        return (int)ans;
        
         
    }
};