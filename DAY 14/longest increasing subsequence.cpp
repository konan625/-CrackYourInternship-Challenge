For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.
https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!
//Recursion
int helper(int arr[],int n,int idx,int prev){
    //base case
    if(idx==n) return 0;
    int len=0+helper(arr,n,idx+1,prev);//not take case
    if(prev==-1 || arr[idx]>arr[prev]){
        len=max(len,1+helper(arr,n,idx+1,idx));
    }
    return len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return helper(arr,n,0,-1);
}

//memoization
#include<bits/stdc++.h>
int helper(int arr[],int n,vector<vector<int>>& t,int idx,int prev){
    //base case
    if(idx==n) return 0;
    if(t[idx][prev+1]!=-1) return t[idx][prev+1];
    int len=0+helper(arr,n,t,idx+1,prev);//not take case
    if(prev==-1 || arr[idx]>arr[prev]){
        len=max(len,1+helper(arr,n,t,idx+1,idx));
    }
    return t[idx][prev+1]=len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> t(n , vector<int> (n+1,-1));
    return helper(arr,n,t,0,-1);
    
    
}
//runtime because 10^5 x 10^5 matrix is taking lot of space

//Tabulisation
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
    vector<int> dp(n,1);
    int mx=INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i]=1+dp[j];
            }
        }
    }
    for(int x:dp) mx=max(mx,x);
    return mx;
        
    }
};

//BEST NlogN Binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int x: nums){
            auto it=std::lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end()) lis.push_back(x);
            else *it=x;
        }
        return lis.size();
    }
};
