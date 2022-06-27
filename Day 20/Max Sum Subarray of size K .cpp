class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0;
        long sum=0;
        long mx=INT_MIN;
        while(j<N){
            sum+=Arr[j];
            if(j-i+1<K){
                j++;
            }else if(j-i+1==K){
                mx=max(mx,sum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};