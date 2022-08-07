class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])==m.end()){
                 m[nums[i]]=i;
            }
        }
        vector<int> ans(n);
        int i=0,j=0;
        while(i<n){
            int curr=temp[i];
            while(i<n && curr==temp[i]){
                ans[i]=m[temp[i]];
                i++; 
            }
        }
        return ans;
    }
};