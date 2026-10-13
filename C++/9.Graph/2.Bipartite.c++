// LeetCode Problem: 785. Is Graph Bipartite?
// Problem Link: https://leetcode.com/problems/is-graph-bipartite/

// A graph is bipartite when its nodes can be split into two sets so every edge
// joins the two sets. That is the same as coloring the graph with two colors:
// adjacent nodes must get different colors. An odd cycle makes this impossible.


class Solution {
    public:
        // DFS coloring. curr is this node's color, 0 or 1. curr ^ 1 flips it
        // to the opposite color. An uncolored neighbour is colored with that
        // opposite color. A neighbour that already has curr means both ends of
        // an edge share a color, so the graph is not bipartite.
        bool solve(vector<vector<int>>& graph, vector<int>& color, int node, int curr) {
            color[node] = curr;
    
            for (int nei : graph[node]) {
                if (color[nei] == -1) {
                    if (!solve(graph, color, nei, curr ^ 1))
                        return false;
                }
                else if (color[nei] == curr) {
                    return false;
                }
            }
            return true;
        }
    
        // -1 means uncolored. Start a coloring from every uncolored node so
        // disconnected components are checked. One failed component means the
        // whole graph is not bipartite.
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, -1);
    
            for (int i = 0; i < n; i++) {
                if (color[i] == -1 && !solve(graph, color, i, 0))
                    return false;
            }
            return true;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)
    };
