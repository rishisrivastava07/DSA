//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfsTraversal(int src, bool vis[], vector<int> adjList[]){
        vis[src] = true;
        
        for(auto it : adjList[src]){
            if(!vis[it]){
                dfsTraversal(it, vis, adjList);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        // change the matrix to list
        vector<int> adjList[V];
        for(int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // count provinces
        int cnt = 0;
        bool vis[V] = {false};
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                cnt ++;
                dfsTraversal(i, vis, adjList);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends