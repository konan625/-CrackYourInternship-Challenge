// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k1=0,c1=0;
        int k2=nums[0],c2=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==k1){
                c1++;
            }
            else if(nums[i]==k2){
                c2++;
            }
            else if(c1==0){
                k1=nums[i];
                c1=1;
            }
            else if(c2==0){
                k2=nums[i];
                c2=1;
            }
            else {
                c1--;c2--;
            }   
        }
        int ca=0,cb=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k1){
                ca++;
            }
            else if(nums[i]==k2){
                cb++;
            }
        }
        vector<int> ans;
        if(ca   >   nums.size()    /   3){
            ans.push_back(k1);
        }
        if(cb > nums.size() / 3){
            ans.push_back(k2);
        }
        return ans;
        
    }
};