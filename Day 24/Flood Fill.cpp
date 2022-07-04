An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
class Solution {
public:
    vector<int> dr{-1,1,0,0};
    vector<int> dc{0,0,1,-1};
    void helper(vector<vector<int>>& image,int sr, int sc,int old,int color){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]==color || image[sr][sc]!=old) return;
        image[sr][sc]=color;
        for(int k=0;k<4;k++){
            helper (image,sr+dr[k],sc+dc[k],old,color);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image,sr,sc,image[sr][sc],color);
        return image;
    }
};