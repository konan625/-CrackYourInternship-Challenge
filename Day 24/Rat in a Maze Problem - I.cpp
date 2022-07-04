Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

class Solution{
    public:
    void dfs(vector<string>& ans,string path,vector<vector<int>> &m,vector<vector<int>> &vis,int i,int j){
        if(i<0 || j<0 || i>=m.size() || j>=m[0].size() || m[i][j]==0 || vis[i][j]==1) return;
        if(i==m.size()-1 && j==m[0].size()-1) {
            ans.push_back(path);
            return;
        }
        vis[i][j]=1;
        //up i-1,j
        dfs(ans,path+'U',m,vis,i-1,j);
        
        //down i+1,j
        dfs(ans,path+'D',m,vis,i+1,j);
        
        //left i, j-1
        dfs(ans,path+'L',m,vis,i,j-1);
        
        //right i,j+1
        dfs(ans,path+'R',m,vis,i,j+1);
        vis[i][j]=0;//because there can be multiple paths from this cell
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        dfs(ans,"",m,vis,0,0);
        return ans;
    }
};