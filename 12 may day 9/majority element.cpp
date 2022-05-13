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

//Moore's Vooting Algorithm
https://www.youtube.com/watch?v=3tbjwaGC-ng
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pc=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(pc==nums[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                pc=nums[i];
                count=1;
            }
        }
        // int c=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==pc){
        //         c++;
        //     }
        // }
        // if(c>(nums.size()/2)){
        //     return pc;
        // }
        return pc;
    }
};