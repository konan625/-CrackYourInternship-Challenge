You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
for revision https://leetcode.com/problems/min-cost-climbing-stairs/discuss/476388/4-ways-or-Step-by-step-from-Recursion-greater-top-down-DP-greater-bottom-up-DP-greater-fine-tuning

//recursion
class Solution {
public:
    int helper(vector<int>& cost,int idx){
        if(idx<0) return 0;
        if(idx==0 || idx==1) return cost[idx];
        return cost[idx]+min(helper(cost,idx-1),helper(cost,idx-2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(helper(cost,n-1),helper(cost,n-2));     
    }
};

//dp
//from last index to zeroth index
class Solution {
public:
    int helper(vector<int>& cost,int idx,vector<int>& dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        if(idx==0 || idx==1) return dp[idx]=cost[idx];
        return dp[idx]=cost[idx]+min(helper(cost,idx-1,dp),helper(cost,idx-2,dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,n-1,dp),helper(cost,n-2,dp));     
    }
};

//from first index to last index
    int helper(vector<int>& cost,int idx,vector<int>& dp){
        if(idx>=cost.size()) return INT_MAX;
        if(dp[idx]!=-1) return dp[idx];
        if(idx==cost.size()-1 || idx==cost.size()-2) return dp[idx]=cost[idx];
        return dp[idx]=cost[idx]+min(helper(cost,idx+1,dp),helper(cost,idx+2,dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,0,dp),helper(cost,1,dp));     
    }
