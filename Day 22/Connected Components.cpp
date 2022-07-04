// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int V, vector<vector<int>>& adj,vector<int>& visited,int node) {
        if(visited[node]) return;
        visited[node]=1;
        // for(auto x:adj[node]){
        //     dfs(adj,visited,x);//NOT AN ADJACENCY LIST
        // } HERE ADJACENCY MATRIX IS USED SO WE CAN USE THIS
        for(int j=0;j<V;j++){
            if(adj[node][j]==1){
                dfs(V,adj,visited,j);
            }
        }
        // Code here
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count=0;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
            count++;
            dfs(V,adj,visited,i);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends