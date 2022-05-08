class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            if(nums[n-1]>0) nums[n-1]=nums[n-1]*(-1);
            else ans.push_back(n);
        }
        return ans;
        
    }
};