Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

brute - O(n2)
binary - O(logn) + O(m)
class Solution {
public:
    int bs(vector<int>& v,int n,int target){
        int l=0,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]==target){
                return mid;
            }
            else if(v[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                int search=bs(matrix[i],n-1,target);
                if(search!=-1) return true;
            }
        }
        return false;
        
    }
};

Optimized Solution - O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=0;
        int n=matrix[0].size();
        while(row>=0 && col<n){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) row--;
            else if(matrix[row][col]<target) col++;
        }
        return false;
    }
};
right top corner element as root od BST or left bottom element as root of BST
here we have used left bottom element as root of BST
so if we want to search for target in matrix we can search in BST
if element is more than target  then row-- and if element is less than target the col++