//Using swap sort - Aditya Verma
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        // code here
        int *ans = new int[2];
        int i=0;
        for(int i=0;i<n;i++){
            while(a[a[i]-1]!=a[i]){
                swap(a[a[i]-1],a[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1){
                ans[0]=a[i];
                ans[1]=i+1;
                return ans;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        // code here
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            int idx=abs(a[i])-1;
            if(a[idx]>0){
                a[idx]=-a[idx];
            }else{
                ans[0]=idx+1;;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends