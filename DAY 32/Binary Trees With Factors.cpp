https://leetcode.com/problems/binary-trees-with-factors/
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
class Solution {
public:
nlogn + n*n can be further optimized using sqrt(n) at second loop
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<long,long> m;
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        m[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            long count=1;
            for(auto it:m){
                if(arr[i]%(it.first)==0 && m.find(arr[i]/(it.first))!=m.end()){
                    count+=((it.second)%mod * (m[arr[i]/(it.first)]))%mod;
                }
            }
            m[arr[i]]=count;
        }
        long sum=0;
        for(auto it:m){
            sum=(sum+(it.second))%mod;
        }
        return (int)sum;
    }
};