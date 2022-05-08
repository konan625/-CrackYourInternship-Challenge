// You are given an integer array nums and an integer k.

// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

// Return the maximum number of operations you can perform on the array.

//BRUTE
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=n-1;
        int ans=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                ans++;i++;j--;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }else if(nums[i]+nums[j]<k){
                i++;
            }
        }
        return ans;
        
    }
}; 

//OPTIMISED
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(m[k-nums[i]]!=0){
                c++;
                m[k-nums[i]]--;
            }
            else{
                m[nums[i]]++;
            }
        }
        return c;
        
    }
}; 