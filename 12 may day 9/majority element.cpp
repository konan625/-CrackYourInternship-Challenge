class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int c: nums){
            m[c]++;
            if(m[c]==(nums.size()+1)/2){
                return c;
            }
        }
        return -1;
    }
};