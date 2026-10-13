// Bellman-Ford shortest paths from one source.
// A negative edge can still shorten a path after a node looks finished, so
// every edge is relaxed again on each pass. A simple path has at most V - 1
// edges, so V - 1 passes settle every shortest path.
// edges[i] = {u, v, w} is the directed edge u -> v of weight w.
// These distances are valid when no negative cycle is reachable from src.
// An unreachable node stays at INF.


class Solution {
    public:
        vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
            const int INF = 1e8;
            vector<int> dist(V, INF);
            dist[src] = 0;

            for (int pass = 1; pass <= V - 1; pass++) {
                bool updated = false;

                for (auto& e : edges) {
                    int u = e[0];
                    int v = e[1];
                    int w = e[2];

                    // An edge out of an unreached node cannot start a path.
                    if (dist[u] == INF) {
                        continue;
                    }

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        updated = true;
                    }
                }

                // Nothing changed, so another pass would change nothing either.
                if (!updated) {
                    break;
                }
            }

            return dist;
        }

        // Time complexity: O(V * E)
        // Space complexity: O(V)


        // Detect a negative cycle with one extra relaxation.
        // After V - 1 passes, every simple path has already been settled. If
        // some edge u -> v still has dist[u] + w < dist[v], that distance can
        // be decreased forever by walking a cycle whose total weight is negative.
        // Every distance starts at 0, so every node counts as reached and a
        // negative cycle is found anywhere in the graph. A positive cycle or a
        // zero-weight cycle never makes this strict comparison succeed.
        bool hasNegativeCycle(int V, vector<vector<int>>& edges) {
            vector<int> dist(V, 0);

            for (int pass = 0; pass < V; pass++) {
                bool updated = false;

                for (auto& e : edges) {
                    int u = e[0];
                    int v = e[1];
                    int w = e[2];

                    if (dist[u] + w < dist[v]) {
                        // The Vth pass is past every simple path. An update
                        // here is a negative cycle.
                        if (pass == V - 1) {
                            return true;
                        }

                        dist[v] = dist[u] + w;
                        updated = true;
                    }
                }

                if (!updated) {
                    return false;
                }
            }

            return false;
        }

        // Time complexity: O(V * E)
        // Space complexity: O(V)
    };
