//brute tc :O(n) sc :O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }else{
                ans.push_back(nums[i]);
            }
        }
        while(zero--){
            ans.push_back(0);
        }
        nums=ans;
        
    }
};

//optimised
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }else{
                nums[idx]=nums[i];
                idx++;
            }
        }
        while(idx<n){
            nums[idx]=0;
            idx++;
        }
    }
};
