Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
class Solution {
public:
    int helper(string& word1,string& word2,vector<vector<int>>& t,int i1,int i2){
        //base case
        if(i1==word1.size() && i2==word2.size()){
            return 0;
        }
        if(i1==word1.size()) return word2.size()-i2;
        if(i2==word2.size()) return word1.size()-i1;
        if(t[i1][i2]!=-1) return t[i1][i2];
        if(word1[i1]!=word2[i2]){
            return t[i1][i2]= 1+min(helper(word1,word2,t,i1+1,i2),helper(word1,word2,t,i1,i2+1));
        }
        else{
            return  t[i1][i2]=helper(word1,word2,t,i1+1,i2+1);
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        // if(n1<n2) return minDistance(word2,word1);
        // vector<vector<int>> t(n1,vector<int> (n2,-1));
        // return helper(word1,word2,t,0,0);
        int dp[n1+1][n2+1];
        dp[0][0]=0;
        for(int i=0;i<=n2;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=n1;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
                else{
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[n1][n2];
        
        
    }
};