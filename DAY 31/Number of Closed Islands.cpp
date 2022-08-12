https://leetcode.com/problems/number-of-closed-islands/
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
class Solution {
public:
    bool solve(vector<vector<int>>& grid,int i,int j,int m,int n){
        //base cases
        if(i<0 || j<0 || i==m || j==n ) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        bool left=solve(grid,i,j-1,m,n);
        bool right=solve(grid,i,j+1,m,n);
        bool top=solve(grid,i-1,j,m,n);
        bool bottom=solve(grid,i+1,j,m,n);
        return left && right && top && bottom;  
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        bool left=false,right=false,top=false,bottom=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(solve(grid,i,j,m,n)){
                        ans+=1;
                    }
                }
            }
        }
        return ans;
    }
};