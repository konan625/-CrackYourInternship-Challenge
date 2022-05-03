// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//with recursion
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        return climbStairs(n-1)+climbStairs(n-2);
        
    }
};

//with memoization
class Solution {
public:
    int memo(int n,int*t){
        if(n<=1){
            return 1;
        }
        if(t[n]!=-1){
            return t[n];
        }
        else{
            return t[n]=memo(n-1,t)+memo(n-2,t);
        }
        return t[n];
    }
    int climbStairs(int n) {
        int* t=new int[n+1];
        for(int i=0;i<n+1;i++){
            t[i]=-1;
        }
        return memo(n,t);
        
    }
};

//With top-down(dp)
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};