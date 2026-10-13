// Disjoint Set Union, also called Union-Find.
// Nodes are 0..n-1. Each node starts as its own component.
// find(x) returns the representative of x's component. unite(u, v) merges
// the two components when they differ. Two nodes are connected when they
// share a representative.
// Kruskal uses the same idea with union by rank. Rank is a bound on tree
// height. Size, used here, is the number of nodes in the component.


class DSU {
    public:
        vector<int> parent, size;
        int components;

        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            components = n;

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Time complexity: O(n)
        // Space complexity: O(n)


        // Path compression. Each node on the path from x to the root is
        // attached directly to the root, so a later find on that path skips
        // the old chain.
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        // Time complexity: O(α(n)) amortized


        // Union by size. The smaller component hangs under the larger one, so
        // the tree stays flat. Equal sizes hang one root under the other, and
        // the parent's size becomes the sum.
        // Returns false when u and v were already in the same component.
        bool unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) {
                return false;
            }

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }

            components--;
            return true;
        }

        // Time complexity: O(α(n)) amortized


        bool same(int u, int v) {
            return find(u) == find(v);
        }

        // Time complexity: O(α(n)) amortized


        // Number of nodes in x's component. Read it from the root, because
        // path compression does not copy size onto the children.
        int componentSize(int x) {
            return size[find(x)];
        }

        // Time complexity: O(α(n)) amortized

        // Together, path compression and union by size make each operation
        // almost O(1). α(n) is the inverse Ackermann function, which grows
        // slower than log n. A long run of m operations is O(m α(n)).
    };
