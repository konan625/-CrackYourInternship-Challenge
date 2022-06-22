// You are given an integer array nums. You are initially positioned at the array's first index, and each element 
//in the array represents your maximum jump length at that position.


// Return true if you can reach the last index, or false otherwise.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Peak Valley approach
        //explanation link - https://www.youtube.com/watch?v=muDPTDrpS28
        int reachable=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i>reachable){
                return false;
            }
            reachable=max(reachable,i+nums[i]);
        }
        return true;
        
        // From Dp
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(dp[i-1]<i){return false;}
            dp[i]=max(dp[i-1],i+nums[i]);
             if(dp[i]>=nums.size()-1){return true;}
            if(dp[i]==0){return false;}
           
        }
        return dp[nums.size()-1]>=nums.size()-1;
    }
};