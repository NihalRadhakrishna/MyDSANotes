// Detect a cycle in an undirected graph.
// A visited neighbour is a cycle only when it is not the parent. The edge
// used to reach the current node is not a cycle by itself.
// Run the search from every unvisited node so disconnected components are covered.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Approach 1: DFS
    // Mark the node, then walk each neighbour. An unvisited neighbour is
    // explored with the current node as its parent. A visited neighbour that
    // is not the parent closes a cycle (back edge, parallel edge, or self-loop).
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, node, adj, vis)) {
                    return true;
                }
            } else if (neigh != parent) {
                return true;
            }
        }

        return false;
    }

    bool hasCycleDFS(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(i, -1, adj, vis)) {
                return true;
            }
        }

        return false;
    }

    // Time complexity: O(V + E)
    // Space complexity: O(V)


    // Approach 2: BFS
    // Same parent rule as DFS. Each queue entry stores the node and the node
    // it was reached from. A visited neighbour other than that parent is a cycle.
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q;
        vis[start] = 1;
        q.push({start, -1});

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push({neigh, node});
                } else if (neigh != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasCycleBFS(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && bfs(i, adj, vis)) {
                return true;
            }
        }

        return false;
    }

    // Time complexity: O(V + E)
    // Space complexity: O(V)


    // Approach 3: Disjoint Set Union
    // Process each undirected edge once. If both ends already lie in the same
    // component, the edge closes a cycle. Otherwise merge the two components.
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    bool unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv) {
            return false;
        }

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return true;
    }

    bool hasCycleDSU(int V, vector<pair<int, int>>& edges) {
        vector<int> parent(V), rank(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (auto [u, v] : edges) {
            // unite returns false when u and v were already connected.
            if (!unite(u, v, parent, rank)) {
                return true;
            }
        }

        return false;
    }

    // Time complexity: O(E * α(V)), nearly O(E)
    // Space complexity: O(V)
};


int main() {
    Solution sol;

    // 0 - 1 - 2 - 0 forms a cycle. Vertex 3 is a separate component.
    int V = 4;
    vector<vector<int>> adj(V);
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 3}};

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        if (u != v) {
            adj[v].push_back(u);
        }
    }

    cout << sol.hasCycleDFS(V, adj) << "\n";
    cout << sol.hasCycleBFS(V, adj) << "\n";
    cout << sol.hasCycleDSU(V, edges) << "\n";

    // A tree has no cycle.
    vector<vector<int>> tree(3);
    vector<pair<int, int>> treeEdges = {{0, 1}, {1, 2}};
    tree[0].push_back(1);
    tree[1].push_back(0);
    tree[1].push_back(2);
    tree[2].push_back(1);

    cout << sol.hasCycleDFS(3, tree) << "\n";
    cout << sol.hasCycleBFS(3, tree) << "\n";
    cout << sol.hasCycleDSU(3, treeEdges) << "\n";

    return 0;
}
