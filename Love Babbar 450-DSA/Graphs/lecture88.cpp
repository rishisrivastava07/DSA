#include<unordered_map>
#include <queue>
#include <list>
#include <vector>

void createAdjList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adjList){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool isCyclicBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node){
    unordered_map<int, int> parent;
    
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto i : adjList[frontNode]){
            // neglect condition
            if(visited[i] == true && i != parent[frontNode]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create an adjeceny list
    unordered_map<int, list<int>> adjList;
    createAdjList(edges, adjList);

    // visited array
    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(adjList, visited, i);
            if(ans == 1){
                return "Yes";
            }
        }
    }

    return "No";
}
