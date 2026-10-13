// Dijkstra's shortest paths from one source.
// Every edge weight is non-negative. The unsettled node with the smallest
// distance found so far is settled next, and that distance never improves:
// any later path still has to pass through some other unsettled node and then
// add a non-negative weight.
// For an undirected edge, store it in both directions. A node that cannot be
// reached from the source stays at INF.


class Solution {
    public:
        // Approach 1: min-heap
        // adj[u] holds pairs {v, weight} for each edge u -> v.
        // The min-heap stores candidate distances. The same node can be pushed
        // more than once, so a popped distance larger than the best known one
        // is an old entry and is skipped.
        vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
            const int INF = 1e9;
            vector<int> dist(V, INF);
            dist[src] = 0;

            // A normal queue pops nodes in the order they were discovered.
            // With unequal weights that order is not increasing distance, so
            // the first path found to a node can still be beaten by a lighter
            // path discovered later. The min-heap always pops the smallest
            // distance, and that is what makes the popped distance final.
            // {distance, node}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node]) {
                    continue;
                }

                for (auto [nei, w] : adj[node]) {
                    if (dist[node] + w < dist[nei]) {
                        dist[nei] = dist[node] + w;
                        pq.push({dist[nei], nei});
                    }
                }
            }

            return dist;
        }

        // Time complexity: O((V + E) log V)
        // Space complexity: O(V + E)


        // Approach 2: set
        // The set stores one {distance, node} pair per reached node, ordered
        // by distance. When a shorter path is found, the old pair is erased
        // and the new pair is inserted, so begin() is still the smallest
        // unsettled distance.
        // This is useful when the same node is relaxed many times. The heap
        // keeps every outdated pair until it is popped, which can grow to O(E)
        // entries. The set throws the old pair away, so it stays O(V) and that
        // outdated distance is never processed.
        // Erase and insert are each O(log V), so the time bound matches the
        // heap. The heap is the usual choice when few distances change,
        // because one push costs less than erasing a pair and inserting another.
        vector<int> dijkstraSet(int V, vector<vector<pair<int, int>>>& adj, int src) {
            const int INF = 1e9;
            vector<int> dist(V, INF);
            dist[src] = 0;

            set<pair<int, int>> st;
            st.insert({0, src});

            while (!st.empty()) {
                auto [d, node] = *st.begin();
                st.erase(st.begin());

                for (auto [nei, w] : adj[node]) {
                    if (d + w >= dist[nei]) {
                        continue;
                    }

                    // A node still at INF was never inserted.
                    if (dist[nei] != INF) {
                        st.erase({dist[nei], nei});
                    }

                    dist[nei] = d + w;
                    st.insert({dist[nei], nei});
                }
            }

            return dist;
        }

        // Time complexity: O((V + E) log V)
        // Space complexity: O(V)
    };
