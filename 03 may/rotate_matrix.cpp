// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //reversing each row
        // for(int i=0;i<matrix.size();i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
        //reversing without direct finction
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<(matrix[0].size())/2;j++){
                swap(matrix[i][j],matrix[i][matrix[0].size()-j-1]);
            }
        }
        
    }
};