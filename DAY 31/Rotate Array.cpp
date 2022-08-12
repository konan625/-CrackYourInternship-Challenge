https://leetcode.com/problems/rotate-array/
Given an array, rotate the array to the right by k steps, where k is non-negative.
class Solution {
public:
k*(n+n)
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        while(k--){
            nums.insert(nums.begin(),nums[n-1]);
            nums.erase(nums.begin()+(n));
        }
    }
};