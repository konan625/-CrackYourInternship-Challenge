// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int k=0;k<n-3;k++){
            if(k > 0 && nums[k] == nums[k - 1])  continue;
            int target=t-nums[k];
            for(int i=k+1;i<n-2;i++){
            cout<<"*";
            int l=i+1,h=n-1,sum=target-nums[i];
            if(i>k+1 && nums[i]==nums[i-1]) continue;
            while(l<h){
                if(nums[l]+nums[h]==sum){
                    if(l > i + 1 && nums[l] == nums[l - 1]){
                            l++;
                            continue;
                        }
                        if(h < n - 1 && nums[h] == nums[h + 1]){
                            h--;
                            continue;
                        }
                    ans.push_back({nums[k],nums[i],nums[l],nums[h]});
                    // while(l<h && nums[l]==nums[l+1]) l++;
                    // while(l<h && nums[h]==nums[h-1]) h--;
                    
                    l++;h--;
                }else if(nums[l]+nums[h]<sum){
                    l++;
                }else{
                    h--;
                }
            }
            
        }
        }
        return  ans;
    }
};