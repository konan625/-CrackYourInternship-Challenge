// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> m;
        int sum=0;
        m[sum]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m[sum-k]!=0){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
        
    }
};