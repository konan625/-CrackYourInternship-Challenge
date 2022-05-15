// Given a string s, find the length of the longest substring without repeating characters.
// O(2N) : O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int i=0,j=0;
        int mx=1;
        set<char> m;
        while(j<s.size() && i<s.size()){
            if(m.find(s[j]) == m.end()){
                m.insert(s[j]);
                mx=max(mx,j-i+1);
                j++;
            }else{
                m.erase(s[i]);
                i++;
            }
        }
        return mx;
        
    }
};

// O(N) : O(256) TOOK VERY LESS TIME
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int i=0,j=0;
        int mx=0;
        vector<int> mp(256,-1);
        while(j<s.size()){
            if(mp[s[j]] != -1){
                i=max(mp[s[j]]+1,i);
            }
            mp[s[j]]=j;
            mx=max(mx,j-i+1);
            j++;
        }
    
        return mx;
        
    }
};