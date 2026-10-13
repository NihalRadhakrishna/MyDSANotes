// Topological sort of a directed graph.
// For every edge u -> v, u appears before v in the order.
// A cycle means no such order exists, so both approaches return an empty vector.


class Solution {
    public:
        // Approach 1: Kahn's algorithm
        // A node with indegree 0 has no remaining prerequisites, so it can be
        // taken next. Taking it removes one incoming edge from each neighbour.
        // A neighbour whose indegree falls to 0 is ready and joins the queue.
        // If a cycle remains, those nodes never reach indegree 0.
        vector<int> topoSortKahn(int V, vector<vector<int>>& adj) {
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

            vector<int> order;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);

                for (int nei : adj[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }

            if ((int)order.size() != V) {
                return {};
            }

            return order;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)


        // Approach 2: DFS
        // state 0 is unvisited, 1 is on the current path, 2 is finished.
        // A node is recorded only after every node reachable from it has been
        // recorded. Reversing that finish order places each node before the
        // nodes on its outgoing edges. Meeting a node still on the current
        // path is a back edge, so the graph has a cycle.
        bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
            state[node] = 1;

            for (int nei : adj[node]) {
                if (state[nei] == 1) {
                    return false;
                }
                if (state[nei] == 0 && !dfs(nei, adj, state, order)) {
                    return false;
                }
            }

            state[node] = 2;
            order.push_back(node);
            return true;
        }

        vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
            vector<int> state(V, 0);
            vector<int> order;

            for (int i = 0; i < V; i++) {
                if (state[i] == 0 && !dfs(i, adj, state, order)) {
                    return {};
                }
            }

            reverse(order.begin(), order.end());
            return order;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)
    };
