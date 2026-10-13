// Tarjan's strongly connected components of a directed graph, found in one DFS.
// A component is strongly connected when every node in it can reach every
// other node in it. Every node belongs to exactly one component.
// disc[node] is the time the node was first reached. low[node] is the earliest
// discovery time reachable from its subtree, using tree edges and one edge
// back to a node still on the stack.
// low[node] == disc[node] means nothing in this subtree reaches an older node
// still on the stack, so this node is the root of a component. The stack from
// its top down through this root is that component.


class Solution {
    public:
        int timer;

        void dfs(int node, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
                 vector<int>& inStack, stack<int>& st, vector<vector<int>>& scc) {
            disc[node] = low[node] = timer++;
            st.push(node);
            inStack[node] = 1;

            for (int nei : adj[node]) {
                if (disc[nei] == -1) {
                    dfs(nei, adj, disc, low, inStack, st, scc);
                    low[node] = min(low[node], low[nei]);
                } else if (inStack[nei]) {
                    // nei is still on the active path, so this edge reaches an
                    // older node of the same unfinished component.
                    low[node] = min(low[node], disc[nei]);
                }
            }

            if (low[node] == disc[node]) {
                vector<int> comp;

                while (true) {
                    int cur = st.top();
                    st.pop();
                    inStack[cur] = 0;
                    comp.push_back(cur);

                    if (cur == node) {
                        break;
                    }
                }

                scc.push_back(comp);
            }
        }

        vector<vector<int>> tarjan(int V, vector<vector<int>>& adj) {
            vector<int> disc(V, -1), low(V, -1), inStack(V, 0);
            stack<int> st;
            vector<vector<int>> scc;
            timer = 0;

            for (int i = 0; i < V; i++) {
                if (disc[i] == -1) {
                    dfs(i, adj, disc, low, inStack, st, scc);
                }
            }

            return scc;
        }

        // Time complexity: O(V + E)
        // Space complexity: O(V)
    };
