class Solution {
    typedef pair<int, int> P;
    typedef pair<int, pair<int, int>> p;
    
    int primsAlgo(vector<vector<P>>& adj, int V){
        // Step - 1 : Make an inMST & parent Vector. Also make a min heap
        vector<bool> inMST(V, false);
        vector<int> parentV(V, -1);
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, -1}});
        
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true;
            parentV[node] = parent;
            sum += wt;
            
            for(auto& vec : adj[node]){
                int adjNode = vec.first;
                int adjNode_wt = vec.second;
                
                if(!inMST[adjNode] && parentV[adjNode] == -1){
                    pq.push({adjNode_wt, {adjNode, node}});
                }
            }
        }
        
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // making Adjecency List
        vector<vector<P>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        // Apply prim's algorithm
        return primsAlgo(adj, n);
    }
};