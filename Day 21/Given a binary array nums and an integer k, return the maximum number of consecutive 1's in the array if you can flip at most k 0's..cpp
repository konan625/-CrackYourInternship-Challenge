Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
maximum window with k zeroes
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int len=0;
        while(j<n){
            if(nums[j]==1){
                len=max(len,j-i+1);
                j++;
            }
            else{
                k--;
                while(k<0){
                    if(nums[i]==0){
                        k++;
                    }
                    i++;
                }
                len=max(len,j-i+1);
                j++;
            }
            
        }
        return len;
        
    }
};