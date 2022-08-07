Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

O(n2)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        for(string x:words){
            int i=0,j=0;
            while(i<x.size() && j<s.size()){
                if(x[i]==s[j]){
                    if(i==x.size()-1){
                        count++;
                        i++;
                    }
                    else{
                        i++;j++;
                    }
                }
                else{
                    j++;
                }
            }
        }
        return count;
    }
};