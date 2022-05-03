// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mn=nums[0];
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mn,mx);
            }
            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            ans=max(mx,ans);
        }
        return ans;
        
    }
};