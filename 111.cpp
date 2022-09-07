// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?page=1&category[]=DFS&sortBy=submissions
/*
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int v, int par, vector<int> g[], bool visited[]) {
	    visited[v] =  true;
	    bool isLoopExists = false;
	    for (auto &child: g[v]) {
		    if (visited[child] && child == par) continue;
		    if (visited[child]) return true;
		    isLoopExists |= dfs(child, v, g, visited);
		    if (isLoopExists) break;
	    }
	    return isLoopExists;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V+1];
        for (int i = 0; i <= V+1; i++)
            visited[i] = 0;
        bool cycleExists = false;
	    for (int v = 0; v < V; ++v) {
		    if (visited[v]) continue;
		    cycleExists = dfs(v, -1, adj, visited);
		    if (cycleExists) return true;
	    }
	    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> graph[N];
vector<bool> visited(N, false);

bool dfs(int v, int par) {
	visited[v] =  true;
	bool isLoopExists = false;
	for (auto &child: graph[v]) {
		if (visited[child] && child == par) continue;
		if (visited[child]) return true;
		isLoopExists |= dfs(child, v);
		if (isLoopExists) break;
	}
	return isLoopExists;
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	bool cycleExists = false;
	for (int v = 1; v <= n; ++v) {
		if (visited[v]) continue;
		cycleExists = dfs(v, 0);
		if (cycleExists) break;
	}
	cout << ((cycleExists)? 1 : 0);
}