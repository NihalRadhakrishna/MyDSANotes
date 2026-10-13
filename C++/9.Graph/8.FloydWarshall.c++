// Floyd-Warshall all-pairs shortest paths.
// dist[i][j] is the shortest i -> j path that may pass through intermediate
// nodes 0..k. A path that uses k is dist[i][k] + dist[k][j], and both of those
// pieces may already use intermediates below k. k stays the outer loop so
// those smaller intermediates are finished before k is used.
// matrix[i][j] is the weight of the directed edge i -> j, or INF when that
// edge is absent. The diagonal starts at 0.
// A negative edge is allowed. After every intermediate has been tried,
// dist[i][i] < 0 means a negative cycle through i, and distances that can
// reach that cycle are not meaningful.


class Solution {
    public:
        vector<vector<int>> floydWarshall(vector<vector<int>>& matrix) {
            int V = matrix.size();
            const int INF = 1e8;
            vector<vector<int>> dist = matrix;

            for (int i = 0; i < V; i++) {
                dist[i][i] = 0;
            }

            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        // A missing half cannot form a path through k.
                        if (dist[i][k] == INF || dist[k][j] == INF) {
                            continue;
                        }

                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            return dist;
        }

        // Time complexity: O(V^3)
        // Space complexity: O(V^2)
    };
