https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
     bool find132pattern(vector<int>& nums) {
        int n=nums.size();
         if(n<3) return false;
         int s3=nums[0];
         stack<pair<int,int>> s;
         for(int i=1;i<n;i++){
             while(s.size() && nums[i]>=s.top().first){
                 s.pop();
             }
             if(s.size() && nums[i]>s.top().second){
                 return true;
             }
             s.push(make_pair(nums[i],s3));
             s3=min(s3,nums[i]);
         }
         return false;
    }
};