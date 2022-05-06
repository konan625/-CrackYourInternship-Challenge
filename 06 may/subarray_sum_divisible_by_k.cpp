// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.
//BRUTE
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum%k==0){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};

//OPTIMAL
//Explanation link - https://www.youtube.com/watch?v=u9m-hnlcydk
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k,0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]%k + k)%k;
            count[sum%k]++;
        }
        int ans=count[0];
        for(int c: count){
            ans+=((c*(c-1))/2);
        }
        return ans;
    }
};