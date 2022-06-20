Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.
Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
//Accepted
class Solution {
public:
    string greatestLetter(string s) {
        vector<int> small(26,0);
        vector<int> capital(26,0);
        string ans="";
        for(char c:s){
            int idx;
            if(islower(c)){
                small[c-97]++;
                idx=c-97;
            } 
            if(isupper(c)){
                capital[c-65]++;
                idx=c-65;
            }
            if(small[idx]>=1 && capital[idx]>=1){
                string temp="";
                temp+=(65+idx);
                if(temp>ans){
                    ans=temp;
                }
            }  
        }
        return ans;
        
    }
};
//better approach
class Solution {
public:
    string greatestLetter(string s) 
    {
        // declare a Hahmap for storing the characters and their occurance
        unordered_map<char, int> mp;
        
        // counting occuracne
        for(auto it: s)
        {
            mp[it]++;
        }
        
        // sort the string so repeated char will be come with together
        sort(s.begin(), s.end());
        
        // declare a ans string that will store our ans
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            // char curr chatr into lowercase and uppercase
            char l = tolower(s[i]);
            char u = toupper(s[i]);
            
            // if both lower and uppercase are present then store it into ans
            // it will take greatest english letter that have occured more than 1 because it will run till n
            if(mp[l] && mp[u])
            {
                ans = u;        // storeing uppercase as given in the question that we need to return uppercase 
            }     
        }
        
        return ans;
    }
};