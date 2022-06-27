Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.'
//Brute
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=0;
        int n=s.size();
        int k=p.size();
        sort(p.begin(),p.end());
        vector<int> ans;
        if(n<k) return {};
        while(j<=n-k){
            string sb=s.substr(j,k);
            sort(sb.begin(),sb.end());
            if(sb==p){
               ans.push_back(j); 
            }
            j++;
            
        }
        return ans;
        
    }
};

//Brute
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=0;
        int n=s.size();
        int k=p.size();
        map<char,int> m;
        for(char c:p) m[c]++;
        vector<int> ans;
        int count=m.size();
        if(n<k) return {};
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;// this character is there in window and map;
                if(m[s[j]]==0){//this particular character is there is window as many times as required
                    count--;//no of distince charaters neede to be found in the window decreased
                }
                //if m[s[j]] is negative that means character is present more than required in the window
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(count==0) ans.push_back(i);
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++; // to maintain the character required to find in next window
                    if(m[s[i]]==1){//m[s[i]]=1 means one distinct charcter is there to find out
                        count++;
                    }
                    //if m[s[i]]==0 means more than required was present (-ve) and now it is present in the required 
                    //amount , already
                }
                i++;
                j++;
            }
            
        }
        return ans;
        
    }
};