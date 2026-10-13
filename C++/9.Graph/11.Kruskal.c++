// Kruskal's minimum spanning tree of an undirected weighted graph.
// The tree connects every node, contains no cycle, and has the smallest total
// edge weight. A connected graph on V nodes has a spanning tree of V - 1 edges.
// Negative weights are allowed. A disconnected graph has no spanning tree, so
// this returns -1.
// edges[i] = {u, v, w}. Store each undirected edge once.


class Solution {
    public:
        int find(int x, vector<int>& parent) {
            if (parent[x] != x) {
                parent[x] = find(parent[x], parent);
            }
            return parent[x];
        }

        // Merge the components of u and v. Same parent means the edge stays
        // inside one component and would close a cycle.
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

        // Sort by increasing weight and add an edge only when its ends lie in
        // different components. The cheapest such edge cannot be improved by a
        // heavier one later.
        // Useful when the graph is given as an edge list, especially a sparse
        // one: the sort is the main cost, and the tree can stop at V - 1 edges.
        int kruskal(int V, vector<vector<int>>& edges) {
            vector<vector<int>> sorted = edges;
            sort(sorted.begin(), sorted.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

            vector<int> parent(V), rank(V, 0);
            for (int i = 0; i < V; i++) {
                parent[i] = i;
            }

            int cost = 0;
            int used = 0;

            for (auto& e : sorted) {
                if (!unite(e[0], e[1], parent, rank)) {
                    continue;
                }

                cost += e[2];
                used++;

                if (used == V - 1) {
                    break;
                }
            }

            if (used != V - 1) {
                return -1;
            }

            return cost;
        }

        // Time complexity: O(E log E)
        // Space complexity: O(V + E)
    };
