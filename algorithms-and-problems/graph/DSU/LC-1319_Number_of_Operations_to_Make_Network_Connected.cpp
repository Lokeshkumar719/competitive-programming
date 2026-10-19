class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp)
            return;

        if (size[up] > size[vp]) {
            size[up] += size[vp];
            parent[vp] = u;
        } else {
            size[vp] += size[up];
            parent[up] = v;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        if (wires < (n - 1))
            return -1;
        DSU dsu(n);
        int ans = n;
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            if (dsu.findParent(u) != dsu.findParent(v)) {
                dsu.unite(u, v);
                ans--;
            }
        }
        return ans - 1;
    }
};