//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long int arr[],long long int l,long long int r,long long int mid,long long int &count){
        vector<long long int> temp(r-l+1);
        long long  int i=l,j=mid+1;
        long long int  k=0;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                count+=mid-i+1;
            }
        }
        while(i<=mid) temp[k++]=arr[i++];
        while(j<=r) temp[k++]=arr[j++];
        k=0;
        for(long long int i=l;i<=r;i++){
            arr[i]=temp[k++];
        }
    }
    void mergesort(long long int arr[],long long int l,long long int r,long long int &count){
        if(l>=r) return ;
            long long int mid=(r+l)/2;
            mergesort(arr,l,mid,count);
            mergesort(arr,mid+1,r,count);
            merge(arr,l,r,mid,count);
            
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int inv=0;
        mergesort(arr,0,N-1,inv);
        return inv;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends