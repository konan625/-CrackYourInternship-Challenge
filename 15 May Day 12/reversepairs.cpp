// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
class Solution {
public:
    int merge(vector<int>& nums,int start,int mid,int end){
        int cnt=0;
        int j=mid+1;
        for(int i=start;i<=mid;i++){
            while(j<=end && nums[i]>2*(long)nums[j]) j++;
            cnt+=(j-(mid+1));
        }
        vector<int> temp;
        int l=start,r=mid+1;
        while(l<=mid && r<=end){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{ 
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=end){
            temp.push_back(nums[r]);
            r++;
        }
        //putting the temp in nums
        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
        return cnt;
    }
    int mergesort(vector<int>& nums,int start,int end){
        if(start>=end) return 0;
        int mid=(start+end)/2;
        int inv=mergesort(nums,start,mid);
        inv+=mergesort(nums,mid+1,end);
        inv+=merge(nums,start,mid,end);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
        
    }
};