Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
public:
    int helper(string& s,string& t,int i1,int i2){
        if(i1==s.size() && i2==t.size()) return 0;
        if(i1==s.size()) return t.size()-i2;
        if(i2==t.size()) return s.size()-i1;
        if(s[i1]==t[i2]){
            return helper(s,t,i1+1,i2+1);
        }
        else{
            int insert=1+helper(s,t,i1,i2+1);
            int rem=1+helper(s,t,i1+1,i2);
            int rep=1+helper(s,t,i1+1,i2+1);
            return min(insert,min(rem,rep));
        }
        
    }
    int editDistance(string s, string t) {
        // Code here
        return helper(s,t,0,0);
    }

//memoization
int helper(string& s,string& t,int i1,int i2,vector<vector<int>>& dp){
        if(i1==s.size() && i2==t.size()) return 0;
        if(i1==s.size()) return t.size()-i2;
        if(i2==t.size()) return s.size()-i1;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s[i1]==t[i2]){
            return dp[i1][i2]=helper(s,t,i1+1,i2+1,dp);
        }
        else{
            int insert=1+helper(s,t,i1,i2+1,dp);//if i am inserting a character in string2 then i cant remove it again
            int rem=1+helper(s,t,i1+1,i2,dp);//for removing i will have to go for string1 , basically take one string as reference and perform the operations
            int rep=1+helper(s,t,i1+1,i2+1,dp);
            return dp[i1][i2]=min(insert,min(rem,rep));
        }
        return dp[i1][i2];
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return helper(s,t,0,0,dp);
    }

//Tabulisation
    int editDistance(string s, string t) {
        // Code here
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        //return helper(s,t,0,0,dp);
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int i=0;i<=n2;i++) dp[0][i]=i;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insert=1+dp[i][j-1];
                    int rem=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(rem,rep));
                }
            }
        }
        return dp[n1][n2];
    }