#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u, v--, u--;
    }

    disjoin_set_union dsu(n);
    vector<bool> in_mst(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        if (dsu.unite(edges[i].first, edges[i].second)) {
            in_mst[i] = true;
            g[edges[i].first].push_back(edges[i].second);
            g[edges[i].second].push_back(edges[i].first);
        }
    }

    vector<int> tin(n), tout(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    auto is_ancestor = [&](int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    };

    vector<int> f(n + 1);
    auto add_on_segment = [&](int l, int r, int val) {
        f[l] += val;
        f[r] -= val;
    };

    for (int i = 0; i < m; i++) {
        if (in_mst[i]) continue;
        auto [v, u] = edges[i];
        if (!is_ancestor(v, u)) swap(v, u);
        if (is_ancestor(v, u)) {
            int pos = partition_point(all(g[v]), [&](const int x) {
                return tin[x] <= tin[u];
            }) - g[v].begin() - 1;
            int w = g[v][pos];
            add_on_segment(0, n, 1);
            add_on_segment(tin[w], tout[w], -1);
        } else {
            add_on_segment(tin[v], tout[v], 1);
        }
        add_on_segment(tin[u], tout[u], 1);
    }

    for (int i = 0; i < n; i++) f[i + 1] += f[i];
    for (int i = 0; i < n; i++) cout << (f[tin[i]] == (m - (n - 1)));
    cout << '\n';
}