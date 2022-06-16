#include<bits/stdc++.h>
int helper(string& s,string& t, vector<vector<int>>& dp,int x,int y){
    if(x==0 || y==0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(s[x-1]==t[y-1]){
        return dp[x][y]= 1 + helper(s,t,dp,x-1,y-1);
    }
    return dp[x][y]=0+max(helper(s,t,dp,x-1,y),helper(s,t,dp,x,y-1));
}
int lcs(string s, string t)
{
	//Write your code here
    int n1=s.size();
    int n2=t.size();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
    return helper(s,t,dp,n1,n2);
}
//dp
int lcs(string s, string t)
{
	//Write your code here
    int n1=s.size();
    int n2=t.size();
//     vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
//     return helper(s,t,dp,n1,n2);
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    for(int i=0;i<=n1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n2;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}