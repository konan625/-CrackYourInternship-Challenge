https://leetcode.com/problems/number-of-enclaves/
 we remove the 1s from boundaries and their routes to inside then after that we count the remaining 1s and we return the result
 class Solution {
public:
    void solve(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || j<0 || i==m || j==n || grid[i][j]==0 ) return ;
        grid[i][j]=0;
        
        solve(grid,i,j-1,m,n);
        solve(grid,i,j+1,m,n);
        solve(grid,i-1,j,m,n);
        solve(grid,i+1,j,m,n);
        return; 
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                solve(grid,i,0,m,n);
            }
            if(grid[i][n-1]==1){
                solve(grid,i,n-1,m,n);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                solve(grid,0,j,m,n);
            }
            if(grid[m-1][j]==1){
                solve(grid,m-1,j,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};