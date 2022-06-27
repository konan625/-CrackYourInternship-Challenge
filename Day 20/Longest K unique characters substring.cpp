Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        map<char,int> m;
        int i=0;
        int j=0;
        int n=s.size();
        int count=0;
        int ans=-1;
        while(j<n){
            if(m[s[j]]>=1){
                m[s[j]]++;
            }else{
                m[s[j]]++;
                count++;
            }
            if(count<k) j++;
            else if(count==k){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                m[s[i]]--;
                if(m[s[i]]==0){
                    count--;
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};