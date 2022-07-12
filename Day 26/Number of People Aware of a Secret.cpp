On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

//Brute 
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int day=1;
        vector<pair<int,int>> m;
        int dA=1+delay;
        int dF=1+forget;
        m.push_back(make_pair(dA,dF));
        int i=2;
        while(i<=n){
            vector<pair<int,int>> n=m;
            int s=m.size();
            for(int j=0;j<s;j++){
                if(i>=n[j].first){
                    if(i<n[j].second){
                        m.push_back(make_pair(i+delay,i+forget));
                    }
                    else{
                        m.erase(m.begin()+j);
                    }
                }
            }
            i++;
        }
        return m.size();
        
    }
};

//Good one
class Solution {
public:
    #define ll  long long
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<=n;i++){
            if(dp[i]>=1){
                int del=i+delay;
                int forg=i+forget-1;
                for(int j=del;j<=n && j<=forg;j++){
                    dp[j]=(dp[j]+dp[i])%1000000007;
                }
                if(forg<n){
                    dp[i]=0;
                }
            }
        }
        ll ans=0;
        for(int x:dp) {
            ans+=x;
            ans=ans%1000000007;
        }
        return ans%1000000007;
    }
};