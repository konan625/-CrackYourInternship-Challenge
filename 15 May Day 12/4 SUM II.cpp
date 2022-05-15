// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

// My Approach Brute
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       int cnt=0;
        map<int,int> m;
        for(int c:nums4){
            m[c]++;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        for(int k=0;k<nums1.size();k++){
            int target1=-nums1[k];
            for(int i=0;i<nums2.size();i++){
                int target2=target1-nums2[i];
                for(int j=0;j<nums3.size();j++){
                    if(m.find(target2-nums3[j])!=m.end()){
                        cnt+=m[target2-nums3[j]];
                    }
                }
                
            }
        }
        return cnt;
    }
};

//OPTIMISED
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       int count=0;
        map<int,int> mp;
        
        //Traversing Part 1
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++; 
        
        // Traversing Part 2
        for(auto &it3: nums3)
            for(auto &it4:nums4)
               if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
        return count;
    }
};