Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.
class Solution{
  public:
  
    bool solve(int a[],int n,vector<int>& vis,int currsum,int sum,int k){
        if(k==0) return true;
        if(currsum==sum){
            currsum=0;
            return solve(a,n,vis,currsum,sum,k-1);
        }
        if(currsum>sum) return false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                if(solve(a,n,vis,currsum+a[i],sum,k)) return true;
                //Backtracking
                vis[i]=0;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k) return false;
         sum=sum/k;
         int currsum=0;
         vector<int> vis(n,0);
         return solve(a,n,vis,currsum,sum,k);
    }
};