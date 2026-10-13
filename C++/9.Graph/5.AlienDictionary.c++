// LeetCode Problem: 269. Alien Dictionary
// Problem Link: https://leetcode.com/problems/alien-dictionary/

// The words are already sorted in the alien alphabet. The first position where
// two adjacent words differ gives one rule: the letter in the earlier word
// comes before the letter in the later word. Each rule is a directed edge.
// A valid alphabet is a topological order of that graph.
// A cycle, or a longer word placed before its own prefix, means no order exists.


class Solution {
    public:
        // Build one edge from each adjacent pair, then run Kahn's algorithm.
        // A letter with indegree 0 has no letter that must come before it, so
        // it can be written next. If a cycle remains, some letters never reach
        // indegree 0 and the order is shorter than the number of used letters.
        string alienOrder(vector<string>& words) {
            vector<vector<int>> adj(26);
            vector<int> indegree(26, 0);
            vector<int> present(26, 0);
            vector<vector<int>> added(26, vector<int>(26, 0));

            for (string& word : words) {
                for (char c : word) {
                    present[c - 'a'] = 1;
                }
            }

            for (int i = 0; i + 1 < (int)words.size(); i++) {
                string& earlier = words[i];
                string& later = words[i + 1];
                int len = min(earlier.size(), later.size());
                bool foundDiff = false;

                for (int j = 0; j < len; j++) {
                    if (earlier[j] == later[j]) {
                        continue;
                    }

                    // The same rule can show up in more than one pair.
                    int u = earlier[j] - 'a';
                    int v = later[j] - 'a';
                    if (!added[u][v]) {
                        added[u][v] = 1;
                        adj[u].push_back(v);
                        indegree[v]++;
                    }

                    foundDiff = true;
                    break;
                }

                // "abc" cannot come before "ab": the shorter word is a prefix,
                // so it must appear first in a sorted dictionary.
                if (!foundDiff && earlier.size() > later.size()) {
                    return "";
                }
            }

            queue<int> q;
            int total = 0;

            for (int i = 0; i < 26; i++) {
                if (!present[i]) {
                    continue;
                }

                total++;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

            string order;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(char('a' + node));

                for (int nei : adj[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }

            if ((int)order.size() != total) {
                return "";
            }

            return order;
        }

        // Time complexity: O(N * L), N words of length up to L
        // Space complexity: O(1), the graph has at most 26 letters
    };
