You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words
https://leetcode.com/problems/longest-string-chain/discuss/2153007/C%2B%2BPython-Simple-Solution-w-Explanation-or-DP

class Solution {
public:
    static bool cmp(string& a,string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        map<string,int> dp;
        int n=words.size();
        //vector<int> dp
        sort(words.begin(),words.end(),cmp);
        for(string s:words){
            dp[s]=1;
            for(int j=0;j<s.size();j++){
                string t=s.substr(0,j)+s.substr(j+1);
                if(dp.find(t)!=dp.end()){
                    dp[s]=max(dp[s],dp[t]+1);
                }
            }
        }
        int mx=INT_MIN;
        for(auto it:dp){
            mx=max(mx,it.second);
        }
        return mx;
        
    }
};