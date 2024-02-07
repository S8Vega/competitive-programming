class Solution {
public:
    struct dsu {
    vector<int> par, sz;
    int size;

    dsu(int n) : par(n), sz(n, 1) {
        size = n;
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
};

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu groups(1001);
        vector<int> ans = edges[0];
        for (vector<int> current: edges) {
            if (groups.find(current[0]) == groups.find(current[1])) {
                ans = current;
                break;
            }
            groups.unite(current[0], current[1]);
        }
        return ans;
    }
};