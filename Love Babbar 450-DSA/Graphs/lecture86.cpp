#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {
    vector<int> res;
    queue<int> q;

    // Start BFS from vertex 0
    q.push(0);

    // Initialize the visited array with all zeros
    vector<bool> vis(n, 0);

    // Mark vertex 0 as visited (1 indicates visited, 0 indicates not visited)
    vis[0] = 1;

    while (!q.empty()) {
        // Get the front vertex from the queue
        int topVertex = q.front();
        q.pop();

        // Add the current vertex to the result vector
        res.push_back(topVertex);

        // Traverse all neighbors of the current vertex
        for (auto neighbor : adj[topVertex]) {
            // If the neighbor is not visited, mark it as visited and enqueue it
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return res;
}