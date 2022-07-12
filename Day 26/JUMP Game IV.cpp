You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.


//Recursion
5/71 , TC = O(K^N), SC= O(N)
class Solution {
public:
    int helper(vector<int>& nums,int k,int i){
        if(i>=nums.size()-1) return nums[nums.size()-1];
        int score=INT_MIN;
        for(int j=i+1;j<=i+k;j++){
            score=max(score,nums[i]+helper(nums,k,j));
        }
        return score;
    }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k,0);
        
    }
};

//Memoization
57/71 , TC = O(K*N), SC = O(N)
class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int k,int i){
        if(dp[i]!=INT_MIN) return dp[i];
        for(int j=i+1;j<=i+k;j++){
            if(j<nums.size()){
                dp[i]=max(dp[i],nums[i]+helper(nums,dp,k,j));
            }
        }
        return dp[i];
    }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        dp[n-1]=nums[n-1];
        return helper(nums,dp,k,0);
    }
};