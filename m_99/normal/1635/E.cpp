#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> E(n);
	vector<int> t(m),a(m),b(m);
	rep(i,m){
		scanf("%d %d %d",&t[i],&a[i],&b[i]);
		a[i]--;b[i]--;
		E[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
	
	vector<int> dis(n,-1);
	rep(i,n){
		
		if(dis[i]!=-1)continue;
		dis[i] = 0;
		queue<int> Q;
		Q.push(i);
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(j,E[u].size()){
				int v = E[u][j];
				if(dis[v]==-1){
					
					dis[v] = dis[u]^1;
					Q.push(v);
				}
				else{
					if(dis[u]==dis[v]){
						cout<<"NO"<<endl;
						return 0;
					}
				}
			}
		}
	}
	
	vector<char> c(n);
	vector<int> x(n);
	rep(i,n){
		if(dis[i]==0)c[i] = 'L';
		else c[i] = 'R';
	}
	scc_graph G(n);
	rep(i,m){
		if(t[i]==1){
			if(dis[a[i]]==1)swap(a[i],b[i]);
		}
		else{
			if(dis[a[i]]==0)swap(a[i],b[i]);
		}
		G.add_edge(a[i],b[i]);
	}
	
	auto s = G.scc();
	if(s.size()!=n){
		cout<<"NO"<<endl;
		return 0;
	}
	
	rep(i,s.size()){
		x[s[i][0]] = i;
	}
	
	cout<<"YES"<<endl;
	rep(i,n){
		cout<<c[i]<<' '<<x[i]<<endl;
	}
	
	return 0;
}