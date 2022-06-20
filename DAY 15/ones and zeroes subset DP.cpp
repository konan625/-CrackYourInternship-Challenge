You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

//memo
class Solution {
public:
    int t[601][101][101]={};
    pair<int,int> number(string& str){
        int zero=0,one=0;
        for(char c:str){
            if(c=='0') zero++;
            else one++;
        }
        pair<int,int> p(zero,one);
        return p;
    }
    int helper(vector<string>& strs,int idx,int m,int n){
        //base cases
        if(idx==strs.size() || (m==0 && n==0)) return 0;
        if(t[idx][m][n]!=-1) return t[idx][m][n];
        string s=strs[idx];
        pair<int,int> p=number(s);
        int zero=p.first,one=p.second;
        if(zero<=m && one<=n){
            t[idx][m][n]=max(1+helper(strs,idx+1,m-zero,n-one),helper(strs,idx+1,m,n));
        }
        else{
            t[idx][m][n]=helper(strs,idx+1,m,n);
        }
        return t[idx][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=0;
        int N=strs.size();
        // return helper(strs,0,m,n,len);
        //vector<int> t(N+1,-1);
        memset(t , -1 , sizeof(t));
        return helper(strs,0,m,n);
        
    }
};

//Tabulisation
class Solution {
public:
    int t[601][101][101]={};
    pair<int,int> number(string& str){
        int zero=0,one=0;
        for(char c:str){
            if(c=='0') zero++;
            else one++;
        }
        pair<int,int> p(zero,one);
        return p;
    }
    int helper(vector<string>& strs,int idx,int m,int n){
        //base cases
        if(idx==strs.size() || (m==0 && n==0)) return 0;
        if(t[idx][m][n]!=-1) return t[idx][m][n];
        string s=strs[idx];
        pair<int,int> p=number(s);
        int zero=p.first,one=p.second;
        if(zero<=m && one<=n){
            t[idx][m][n]=max(1+helper(strs,idx+1,m-zero,n-one),helper(strs,idx+1,m,n));
        }
        else{
            t[idx][m][n]=helper(strs,idx+1,m,n);
        }
        return t[idx][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=0;
        int N=strs.size();
        // return helper(strs,0,m,n,len);
        //vector<int> t(N+1,-1);
        //memset(t , -1 , sizeof(t));
        //return helper(strs,0,m,n);
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>> (m+1,vector<int> (n+1,0)));
        int ans=INT_MIN;
        for(int i=1;i<=N;i++){
            string s=strs[i-1];
            pair<int,int> p=number(s);
            int zero=p.first,one=p.second;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(zero<=j && one<=k){
                        dp[i][j][k]=max(1+dp[i-1][j-zero][k-one],dp[i-1][j][k]);
                    }
                    else{
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                    ans=max(ans,dp[i][j][k]);
                }
            }
        }
        return ans;
    }
};