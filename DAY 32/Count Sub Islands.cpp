https://leetcode.com/problems/count-sub-islands/
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.
class Solution {
public:
    void solve(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,int m,int n,bool& check){
        if(i<0 || j<0 || i==m || j==n || grid2[i][j]==0) return;
        if(grid1[i][j]!=grid2[i][j])  {
            check = false;
            return;
        }
        grid1[i][j]=0,grid2[i][j]=0;
        solve(grid1,grid2,i-1,j,m,n,check);
        solve(grid1,grid2,i+1,j,m,n,check);
        solve(grid1,grid2,i,j-1,m,n,check);
        solve(grid1,grid2,i,j+1,m,n,check);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool check=true;
                if(grid2[i][j]==1){
                    solve(grid1,grid2,i,j,m,n,check);
                    if(check) ans++;
                }
            }
        }
        return ans;
    }
};