There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

//Recursion
class Solution {
public:
    int help(int i,int last_clr,int t,vector<int>& houses,vector<vector<int>>& cost, int m, int n, int target)
    {
        //base cases
        if(t>target) return INT_MAX/2;
        if(i==m){
            return (t==target)? 0:INT_MAX/2;
        }
        else{
            int ans=INT_MAX/2;
            //if not coloured
            if(houses[i]==0){
                //with all colours
                for(int j=0;j<n;j++){
                    ans=min(ans,cost[i][j]+help(i+1,j+1,(last_clr==j+1)?t:t+1,houses,cost,m,n,target));
                }
            }
            else{
                ans=min(ans,help(i+1,houses[i],(houses[i]==last_clr)?t:t+1,houses,cost,m,n,target));
            }
            return ans;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        int ans=help(0,0,0,houses,cost,m,n,target);
        return ans!=(INT_MAX/2)?ans:-1;
    }
};

//Memoization
class Solution {
public:
    //vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n, INF)));
    vector<vector<vector<int>>> dp {101,vector<vector<int>> (21,vector<int>(101,-1))};
    int help(int i,int last_clr,int t,vector<int>& houses,vector<vector<int>>& cost, int m, int n, int target)
    {
        //base cases
        if(t>target) return dp[i][last_clr][t]=INT_MAX/2;
        if(dp[i][last_clr][t]!=-1) return dp[i][last_clr][t];
        if(i==m){
            return dp[i][last_clr][t]=(t==target)? 0:INT_MAX/2;
        }
        else{
            int ans=INT_MAX/2;
            //if not coloured
            if(houses[i]==0){
                //with all colours
                for(int j=0;j<n;j++){
                    ans=min(ans,cost[i][j]+help(i+1,j+1,(last_clr==j+1)?t:t+1,houses,cost,m,n,target));
                }
            }
            else{
                ans=min(ans,help(i+1,houses[i],(houses[i]==last_clr)?t:t+1,houses,cost,m,n,target));
            }
            return dp[i][last_clr][t]=ans;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        int ans=help(0,0,0,houses,cost,m,n,target);
        return ans!=(INT_MAX/2)?ans:-1;
    }
};