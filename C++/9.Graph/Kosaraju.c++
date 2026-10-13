// Kosaraju's strongly connected components of a directed graph.
// A component is strongly connected when every node in it can reach every
// other node in it. Every node belongs to exactly one component.
// The first DFS records a node after its descendants finish. Between two
// components, the one with an outgoing edge finishes later. Reversing the
// edges turns that edge around, so a search started at the later-finishing
// component cannot leave it. Each search on the reversed graph is one component.


class Solution {
    public:
        void dfsFinish(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
            vis[node] = 1;

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    dfsFinish(nei, adj, vis, order);
                }
            }

            order.push_back(node);
        }

        void dfsCollect(int node, vector<vector<int>>& rev, vector<int>& vis, vector<int>& comp) {
            vis[node] = 1;
            comp.push_back(node);

            for (int nei : rev[node]) {
                if (!vis[nei]) {
                    dfsCollect(nei, rev, vis, comp);
                }
            }
        }

        vector<vector<int>> kosaraju(int V, vector<vector<int>>& adj) {
            vector<int> vis(V, 0);
            vector<int> order;

            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    dfsFinish(i, adj, vis, order);
                }
            }

            vector<vector<int>> rev(V);
            for (int u = 0; u < V; u++) {
                for (int v : adj[u]) {
                    rev[v].push_back(u);
                }
            }

            fill(vis.begin(), vis.end(), 0);
            vector<vector<int>> scc;

            for (int i = (int)order.size() - 1; i >= 0; i--) {
                if (vis[order[i]]) {
                    continue;
                }

                vector<int> comp;
                dfsCollect(order[i], rev, vis, comp);
                scc.push_back(comp);
            }

            return scc;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V + E)
    };
