https://leetcode.com/problems/as-far-from-land-as-possible/
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|
Brute 
class Solution {
public:
    //we can save the pairs of all 1's coordinates
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> land;
        vector<pair<int,int>> water;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    land.push_back(make_pair(i,j));
                }
                else{
                    water.push_back(make_pair(i,j));
                }
            }
        }
        // land = (0,0),(0,2), (2,0),(2,2)
        //     water = (0,1) (1,0) (1,1) (1,2) (2,1)
        int res=-1;
        for(int i=0;i<water.size();i++){
            int x1=water[i].first;
            int y1=water[i].second;
            int dis=INT_MAX;;
            for(int j=0;j<land.size();j++){
                int x2=land[j].first;
                int y2=land[j].second;
                dis=min(dis,abs(x1-x2)+abs(y1-y2));
                //minimum for nearest
            }
            if(dis!=INT_MAX){
            res=max(res,dis);
            }
            //maximum for maximum nearest land cell
        }
        return res;
    }
};