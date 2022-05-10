// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && helper(board,word,i,j,0)){
                    return true;
                }
            }
        } 
        return false;
    }
    bool helper(vector<vector<char>>& board,string &word,int i,int j,int index){
        //base case
        if(index==word.size()) return true;
        //false cases
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]){
            return false;
        }
        char c=board[i][j];
        board[i][j]='*';
        bool left=helper(board,word,i,j-1,index+1);
        bool right=helper(board,word,i,j+1,index+1);
        bool top=helper(board,word,i-1,j,index+1);
        bool bottom=helper(board,word,i+1,j,index+1);
        if( left || right || top || bottom){
            return true;
        }
        booard[i][j]=c;
        return false;
    }
};