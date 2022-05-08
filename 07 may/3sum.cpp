// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.
//BRute
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};
//Optimisation 1 TC(N^2logn)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> m;
        set<vector<int>> s;
        for(int c:nums) m[c]++;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]--;
            int target=-(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                m[nums[j]]--;
                if(m[target-nums[j]]!=0){
                    vector<int> temp {nums[i],nums[j],target-nums[j]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};

//OPTIMIZED 2 TC: O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,h=nums.size()-1,sum=0-nums[i];
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            while(l<h){
                if(nums[l]+nums[h]==sum){
                    ans.push_back({nums[i],nums[l],nums[h]});
                    while(l<h && nums[l]==nums[l+1]) l++;
                    while(l<h && nums[h]==nums[h-1]) h--;
                    l++;h--;
                }else if(nums[l]+nums[h]<sum){
                    l++;
                }else{
                    h--;
                }
            }
            }
        }
        return ans;
    }
};