// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long nn=n;
        if(n<0){
            nn=nn*(-1);
        }
        while(nn>0){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        if(n<0){
            ans=1/ans;
        }
        
       
        return ans;  
    }
};