A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.
class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0;
        int j=0;
        string c="";
        int count=0;
        while(j<s.size()){
            c+=s[j];
            if(j-i+1<3){
                j++;
            }else if(j-i+1==3){
                if(c[0]!=c[1] && c[1]!=c[2] && c[0]!=c[2]) count++;
                c.erase(0,1);
                i++;
                j++;
            }
        }
        return count;
        
    }
};