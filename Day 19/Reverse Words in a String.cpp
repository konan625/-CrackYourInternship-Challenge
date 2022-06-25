Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Approach 1 saving the words and making a new string with required format
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int trailingspaces=0;
        int i=0;
        while(s[i]==' ') i++;
        while(i<s.size()){
            string a="";
            while( i!=s.size() && s[i]!=' '){
                a+=s[i];
                i++;
            }
            while(i<s.size() && s[i]==' ') i++;
            words.push_back(a);
        }
        reverse(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            if(i==0) ans+=words[i];
            else{
                ans+=" ";
                ans+=words[i];
            }
        }
        return ans;
        
    }
};

//With Constant Space
class Solution {
public:
    void reverseword(string& s,int i,int j){
        while(i<j){
            char t=s[i];
            s[i++]=s[j];
            s[j--]=t;
        }
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int wordstart=0;
        int wordcount=0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            if(wordcount) s[j++]=' ';
            wordstart=j;
            while(i<n && s[i]!=' '){
                s[j]=s[i];
                i++;j++;
            }
            reverseword(s,wordstart,j-1);
            wordcount++;
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        return s;
        
        
    }
};