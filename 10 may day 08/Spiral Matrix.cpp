class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=n-1,top=0,bottom=m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            //left to right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //right to bottom
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){ // condition because in mxn where m!=n cannot be traversed since at some step top will become > bottom ans same goes for left and right
            //right to left
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            }
            bottom--;
            //bottom to top
            if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            }
            left++;
        }

        return ans;
    }
};