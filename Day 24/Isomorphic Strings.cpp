Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

https://leetcode.com/problems/isomorphic-strings/discuss/1166277/Simple-solution-using-one-Hashmap.
class Solution {
public:
    bool helper(string& s, string& t){
        map<char,char> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]==t[i]) continue;
                else return false;
            }
            else{
                m[s[i]]=t[i];      
            }
            
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
        
        
    }
};