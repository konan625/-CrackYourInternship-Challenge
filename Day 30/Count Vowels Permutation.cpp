https://leetcode.com/problems/count-vowels-permutation/

Explanation
https://leetcode.com/problems/count-vowels-permutation/discuss/1315039/Optimization-from-Brute-Force-to-DP-to-O(1)-Time-Solutions-or-Explained
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

brute
class Solution {
public:
    void solve(int idx,int n,char c,int& count){
        if(idx==n-1) {
            count++;
            return;
        }
        if(c=='a'){
            solve(idx+1,n,'e',count);
            return;
        }
        if(c=='e'){
            solve(idx+1,n,'a',count);
            solve(idx+1,n,'i',count);
            return;
        }
        if(c=='i'){
            solve(idx+1,n,'a',count);
            solve(idx+1,n,'e',count);
            solve(idx+1,n,'o',count);
            solve(idx+1,n,'u',count);
            return;
        }
        if(c=='o'){
            solve(idx+1,n,'i',count);
            solve(idx+1,n,'u',count);
            return;
        }
        if(c=='u'){
            solve(idx+1,n,'a',count);
            return;
        }
    }
    int countVowelPermutation(int n) {
        vector<char> vowels{'a','e','i','o','u'};
        int ans=0;
        for(int i=0;i<5;i++){
            int count=0;
            solve(0,n,vowels[i],count);
            ans+=count;
        }
        return ans;
    }
};

Memoizaion
class Solution {
public:
    int m=1e9 + 7;
    int solve(int idx,int n,char c,int ccount,vector<vector<int>>& dp){
        if(dp[idx][ccount]){
            return dp[idx][ccount]%m;
        }
        if(idx==n-1) {
            dp[idx][ccount]=1;
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
         
        if(c=='a'){
            dp[idx][ccount]+=(solve(idx+1,n,'e',1,dp)%m);
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
        if(c=='e'){
            dp[idx][ccount]+=(solve(idx+1,n,'a',0,dp)%m);
            dp[idx][ccount]%=m;
            dp[idx][ccount]+=(solve(idx+1,n,'i',2,dp)%m);
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
        if(c=='i'){
            dp[idx][ccount]+=(solve(idx+1,n,'a',0,dp)%m);
            dp[idx][ccount]%=m;
            dp[idx][ccount]+=(solve(idx+1,n,'e',1,dp)%m);
            dp[idx][ccount]%=m;
            dp[idx][ccount]+=(solve(idx+1,n,'o',3,dp)%m);
            dp[idx][ccount]%=m;
            dp[idx][ccount]+=(solve(idx+1,n,'u',4,dp)%m);
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
        if(c=='o'){
            dp[idx][ccount]+=(solve(idx+1,n,'i',2,dp)%m);
            dp[idx][ccount]%=m;
            dp[idx][ccount]+=(solve(idx+1,n,'u',4,dp)%m);
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
        if(c=='u'){
            dp[idx][ccount]+=(solve(idx+1,n,'a',0,dp)%m);
            dp[idx][ccount]%=m;
            return dp[idx][ccount]%m;
        }
        return dp[idx][ccount]%m;
    }
    int countVowelPermutation(int n) {
        vector<char> vowels{'a','e','i','o','u'};
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(5,0));
        for(int i=0;i<5;i++){
            int count=0;
            ans+=(solve(0,n,vowels[i],i,dp)%m);
            //ans+=count;
            ans%=m;
        }
        return ans%m;
    }
};