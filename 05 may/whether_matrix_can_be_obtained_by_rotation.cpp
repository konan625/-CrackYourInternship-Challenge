// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
class Solution {
public:
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void rotate(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=i+1;j<mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(check(mat,target)){
            return true;
        }
        rotate(mat);
        if(check(mat,target)){
            return true;
        }
        rotate(mat);
        if(check(mat,target)){
            return true;
        }
        rotate(mat);
        if(check(mat,target)){
            return true;
        }
        return false;
    }
};