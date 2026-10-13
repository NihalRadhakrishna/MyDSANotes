// Prim's minimum spanning tree of an undirected weighted graph.
// The tree connects every node, contains no cycle, and has the smallest total
// edge weight. A connected graph on V nodes has a spanning tree of V - 1 edges.
// Negative weights are allowed. A disconnected graph has no spanning tree, so
// this returns -1.
// adj[u] holds pairs {v, weight}. Store each undirected edge in both directions.


class Solution {
    public:
        // Grow one tree from node 0. The min-heap holds edges that leave the
        // current tree, and the lightest of them is the next tree edge.
        // The heap key is that single edge weight. A node is finished once it
        // joins the tree, so a heavier leftover edge to it is skipped.
        // Useful when the graph is already an adjacency list. On a dense graph,
        // scanning every node for the next cheapest edge is O(V^2) and drops
        // the heap.
        int prim(int V, vector<vector<pair<int, int>>>& adj) {
            vector<int> inTree(V, 0);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, 0});
            int cost = 0;
            int used = 0;

            while (!pq.empty()) {
                auto [w, node] = pq.top();
                pq.pop();

                if (inTree[node]) {
                    continue;
                }

                inTree[node] = 1;
                cost += w;
                used++;

                for (auto [nei, wt] : adj[node]) {
                    if (!inTree[nei]) {
                        pq.push({wt, nei});
                    }
                }
            }

            if (used != V) {
                return -1;
            }

            return cost;
        }

        // Time complexity: O((V + E) log V)
        // Space complexity: O(V + E)
    };
