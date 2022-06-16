For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.

//Recursion
int helper(int arr[],int n,int idx,int prev){
    //base case
    if(idx==n) return 0;
    int len=0+helper(arr,n,idx+1,prev);//not take case
    if(prev==-1 || arr[idx]>arr[prev]){
        len=max(len,1+helper(arr,n,idx+1,idx));
    }
    return len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return helper(arr,n,0,-1);
}
