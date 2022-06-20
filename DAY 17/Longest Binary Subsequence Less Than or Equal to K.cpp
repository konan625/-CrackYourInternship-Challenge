You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.

//Greedy
https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/discuss/2168393/Simple-O(n)-time-O(1)-space-wo-DP-solution
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero=0;
        for(char c:s){
            if(c=='0') zero++;
        }
        int len=0;
        int base=1;
        int num=0;
        for(int i=s.size()-1;i>=0;i--){
            if(num+base>k) break;
            if(s[i]=='1'){
                num+=base;
            }
            else{
                zero--;
            }
            len++;
            base=base*2;
        }
        return len+zero;
        
    }
};

//DP 
https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/discuss/2168246/C%2B%2B-oror-DP
class Solution {
public:
    int helper(int n,string& s,int sum,int len,vector<vector<int>>& t){
        if(n==0) return 0;
        if(t[n][len]!=-1) return t[n][len];
        int no=t[n][len]=helper(n-1,s,sum,len,t);
        int yes=0;
        if(pow(2,len)*(s[n-1]-'0')<=sum){
            t[n][len]=yes=1+helper(n-1,s,sum-(pow(2,len)*(s[n-1]-'0')),len+1,t);
        }
        return t[n][len]=max(yes,no);
    }
    int longestSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return helper(s.size(),s,k,0,t);
    }
};