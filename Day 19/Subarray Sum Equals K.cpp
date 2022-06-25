Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array

//Brute
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size(); 
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){ans++;}
            }
        }
        return ans;
        
    }
};

//Storing the prefix sum , and checking if currsum-k==val(in our map) so it exist and we have an array with a sum=k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
        
    }
};