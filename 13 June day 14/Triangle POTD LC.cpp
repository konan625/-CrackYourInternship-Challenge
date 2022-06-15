// Given a triangle array, return the minimum path sum from top to bottom.


// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//Recursion
int helper(vector<vector<int>>& tri,int sum,int matidx,int idx){
        if(matidx==tri.size()){
            return sum;
        }
        int sum1=helper(tri,sum+tri[matidx][idx],matidx+1,idx);
        int sum2=helper(tri,sum+tri[matidx][idx+1],matidx+1,idx+1);
        return min(sum1,sum2);   
    }
int minimumTotal(vector<vector<int>>& tri) {
        int sum=tri[0][0];
        return helper(tri,sum,1,0);  
    }

//Memoization
int helper(vector<vector<int>>& tri,vector<vector<int>>& t,int matidx,int idx){
        if(matidx+1>=tri.size()){
            return tri[matidx][idx];
        }
        if(t[matidx][idx]!=INT_MAX){
            return t[matidx][idx];
        }
        t[matidx][idx]=tri[matidx][idx]+min(helper(tri,t,matidx+1,idx),helper(tri,t,matidx+1,idx+1));
        return t[matidx][idx];    
    }
int minimumTotal(vector<vector<int>>& tri) {
        vector<vector<int>> t(tri.size(),vector<int>(tri.size(),INT_MAX));
        return helper(tri,t,0,0);   
    }

//Dynamic Programming
int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[n-1][i]=tri[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<tri[i].size();j++){
                dp[i][j]=tri[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];   
    }