// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool row=false,col=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0){row=true;}//we have kept the first row and col arrays as a mark for further calculations
                    if(j==0){col=true;}  
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(row){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        
    }
};