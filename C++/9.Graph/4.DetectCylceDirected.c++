// Detect a cycle in a directed graph.
// An edge back to a node still on the current path is a cycle.
// An edge to a node whose whole search has already finished is not a cycle.
// Start from every unvisited node so disconnected components are covered.


class Solution {
    public:
        // Approach 1: DFS
        // state 0 is unvisited, 1 is on the current path, 2 is finished.
        // Mark the node as on the path, then follow each outgoing edge.
        // A neighbour still in state 1 is a back edge, so this path is a cycle.
        // A neighbour in state 2 was fully explored earlier and can be skipped.
        bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
            state[node] = 1;

            for (int nei : adj[node]) {
                if (state[nei] == 1) {
                    return true;
                }
                if (state[nei] == 0 && dfs(nei, adj, state)) {
                    return true;
                }
            }

            state[node] = 2;
            return false;
        }

        bool hasCycleDFS(int V, vector<vector<int>>& adj) {
            vector<int> state(V, 0);

            for (int i = 0; i < V; i++) {
                if (state[i] == 0 && dfs(i, adj, state)) {
                    return true;
                }
            }

            return false;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)


        // Approach 2: Kahn's algorithm
        // Repeatedly remove a node whose indegree is 0. A cycle has no such
        // node left inside it, so those nodes are never removed. If fewer than
        // V nodes are removed, the remaining nodes form a cycle.
        bool hasCycleKahn(int V, vector<vector<int>>& adj) {
            vector<int> indegree(V, 0);

            for (int u = 0; u < V; u++) {
                for (int v : adj[u]) {
                    indegree[v]++;
                }
            }

            queue<int> q;
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

            int visited = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                visited++;

                for (int nei : adj[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }

            return visited != V;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)
    };
