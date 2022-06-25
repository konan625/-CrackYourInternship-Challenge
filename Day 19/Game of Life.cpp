//Brute
class Solution {
public:
    int live(vector<vector<int>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        int livecount=0;
        if(i-1>=0 && board[i-1][j]==1){livecount++;}
        if(j-1>=0 && board[i][j-1]==1){livecount++;}
        if(i+1<m && board[i+1][j]==1){livecount++;}
        if(j+1<n && board[i][j+1]==1){livecount++;}
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1){livecount++;}
        if(i-1>=0 && j+1<n && board[i-1][j+1]==1){livecount++;}
        if(i+1<m && j-1>=0 && board[i+1][j-1]==1){livecount++;}
        if(i+1<m && j+1<n && board[i+1][j+1]==1){livecount++;}
        return livecount;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> fake=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int lc=live(fake,i,j);
                if(fake[i][j]==1){
                    if(lc<2){board[i][j]=0;}
                    else if(lc==2 || lc==3){board[i][j]=1;}
                    else {board[i][j]=0;}
                }
                if(fake[i][j]==0 && lc==3){board[i][j]=1;}
            }
        }
        
    }
};

//Optimised - marks for each case 2,3,4,5
class Solution {
public:
    int live(vector<vector<int>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        int livecount=0;
        if(i-1>=0 && board[i-1][j]==1){livecount++;}
        if(j-1>=0 && board[i][j-1]==1){livecount++;}
        if(i+1<m && board[i+1][j]==1){livecount++;}
        if(j+1<n && board[i][j+1]==1){livecount++;}
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1){livecount++;}
        if(i-1>=0 && j+1<n && board[i-1][j+1]==1){livecount++;}
        if(i+1<m && j-1>=0 && board[i+1][j-1]==1){livecount++;}
        if(i+1<m && j+1<n && board[i+1][j+1]==1){livecount++;}
        return livecount;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int lc=0;
                if(i-1>=0 && (board[i-1][j]==1 ||  board[i-1][j]==2 || board[i-1][j]==3 || board[i-1][j]==4)){lc++;}
                if(j-1>=0 && (board[i][j-1]==1 ||  board[i][j-1]==2 || board[i][j-1]==3 || board[i][j-1]==4)){lc++;}
                if(i+1<m && (board[i+1][j]==1 ||  board[i+1][j]==2 || board[i+1][j]==3 || board[i+1][j]==4)){lc++;}
                if(j+1<n && (board[i][j+1]==1 ||  board[i][j+1]==2 || board[i][j+1]==3 || board[i][j+1]==4)){lc++;}
                if(i-1>=0 && j-1>=0 && (board[i-1][j-1]==1 ||  board[i-1][j-1]==2 || board[i-1][j-1]==3 || board[i-1][j-1]==4)){lc++;}
                if(i-1>=0 && j+1<n && (board[i-1][j+1]==1 ||  board[i-1][j+1]==2 || board[i-1][j+1]==3 || board[i-1][j+1]==4)){lc++;}
                if(i+1<m && j-1>=0 && (board[i+1][j-1]==1 ||  board[i+1][j-1]==2 || board[i+1][j-1]==3 || board[i+1][j-1]==4)){lc++;}
                if(i+1<m && j+1<n && (board[i+1][j+1]==1 ||  board[i+1][j+1]==2 || board[i+1][j+1]==3 || board[i+1][j+1]==4)){lc++;}
                
                if(board[i][j]==1 && lc<2) board[i][j]=2;
                if(board[i][j]==1 && (lc==2 || lc==3)) board[i][j]=3;
                if(board[i][j]==1 && lc>3) board[i][j]=4;
                if(board[i][j]==0 && lc==3) board[i][j]=5;
                
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2 || board[i][j]==4) board[i][j]=0;
                if(board[i][j]==3 || board[i][j]==5) board[i][j]=1;
            }
        }
        
    }
};