// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
class Solution {
public:
    bool binarysearch(vector<int>& v,int target){
        int low=0;
        int high=v.size()-1;
        while(low<=high){
            int mid=low+((high - low)/2);
            if(v[mid]==target){
                return true;
            }else if(v[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]<=target && matrix[i][j]>=target){
                return binarysearch(matrix[i],target);
            }
        }
        return false;
    }
};