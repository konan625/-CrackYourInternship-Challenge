Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
class Solution {
public:
    vector<int> dr{-1,1,0,0};
    vector<int> dc{0,0,1,-1};
    void explore_neighbours(vector<vector<char>>& grid,int i,int j,int m,int n){
        //if out of bound or not desired value of cell
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
        //mark that cell visited for not considering it again and again
        grid[i][j]='0';
        //call on neighbours
        for(int k=0;k<4;k++){
            explore_neighbours (grid,i+dr[k],j+dc[k],m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    explore_neighbours(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};