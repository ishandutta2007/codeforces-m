#line 1 "/home/maspy/compro/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(u32 x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(u64 x) { return 63 - __builtin_clzll(x); }
// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)
int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(u32 x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(u64 x) { return 63 - __builtin_clzll(x); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename T, typename CNT = int>
vc<CNT> bincount(vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  // stable
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}
#line 1 "/home/maspy/compro/library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};
template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

struct Scanner {
  FILE* fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T, is_modint_t<T> * = nullptr>
  bool read_single(T &ref) {
    long long val = 0;
    bool f = read_single(val);
    ref = T(val);
    return f;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <class A, class B, class C>
  bool read_single(tuple<A, B, C> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)));
  }
  template <class A, class B, class C, class D>
  bool read_single(tuple<A, B, C, D> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)) && read_single(get<3>(p)));
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string &s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double &x) {
    ostringstream oss;
    oss << setprecision(12) << x;
    string s = oss.str();
    write(s);
  }
  template <class T, is_modint_t<T> * = nullptr>
  void write(T &ref) {
    write(ref.val);
  }
  template <class T>
  void write(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> &val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
};

Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)           \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 2 "/home/maspy/compro/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
struct Graph {
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    int l, r;
    const Graph* G;
  };

  bool is_prepared() { return prepared; }
  constexpr bool is_directed() { return directed; }

  Graph() : N(0), M(0), prepared(0) {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared && 0 <= frm && 0 <= to);
    chmax(N, frm + 1);
    chmax(N, to + 1);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  void read_tree(bool wt=false, int off=1){
    read_graph(N - 1, wt, off);
  }

  void read_graph(int M, bool wt=false, int off=1){
    FOR_(M){
      INT(a, b);
      a -= off, b -= off;
      if(!wt){
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    prepare();
  }

  void read_parent(int off=1){
    FOR3(v, 1, N){
      INT(p);
      p -= off;
      add(p, v);
    }
    prepare();
  }

  void prepare() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& e: edges) {
      indptr[e.frm + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    FOR(v, N) indptr[v + 1] += indptr[v];
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& e: edges) {
      csr_edges[counter[e.frm]++] = e;
      if (!directed)
        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }
};
#line 2 "/home/maspy/compro/library/graph/centroid.hpp"
template <typename Graph>
vc<int> find_centroids(Graph& G) {
  int N = G.N;
  vc<int> par(N, -1);
  vc<int> V(N);
  vc<int> sz(N);
  int l = 0, r = 0;
  V[r++] = 0;
  while (l < r) {
    int v = V[l++];
    for (auto&& e: G[v])
      if (e.to != par[v]) {
        par[e.to] = v;
        V[r++] = e.to;
      }
  }
  FOR_R(i, N) {
    int v = V[i];
    sz[v] += 1;
    int p = par[v];
    if (p != -1) sz[p] += sz[v];
  }

  int M = N / 2;
  auto check = [&](int v) -> bool {
    if (N - sz[v] > M) return false;
    for (auto&& e: G[v]) {
      if (e.to != par[v] && sz[e.to] > M) return false;
    }
    return true;
  };
  vc<int> ANS;
  FOR(v, N) if (check(v)) ANS.eb(v);
  return ANS;
}

template <typename Graph, typename E = int>
struct CentroidDecomposition {
  using edge_type = typename Graph::edge_type;
  using F = function<E(E, edge_type)>;
  Graph& G;
  F f; // (E path value, edge e) -> E new_path_value
  int N;
  vector<int> cdep; // depth in centroid tree
  vc<int> sz;
  vc<int> par;

  CentroidDecomposition(
      Graph& G, F f = [](int x, edge_type e) { return x + e.cost; })
      : G(G), N(G.N), f(f), sz(G.N), par(G.N), cdep(G.N, -1) {
    build();
  }

  int find(int v) {
    vc<int> V = {v};
    par[v] = -1;
    int p = 0;
    while (p < len(V)) {
      int v = V[p++];
      sz[v] = 0;
      for (auto&& e: G[v]) {
        if (e.to == par[v] || cdep[e.to] != -1) continue;
        par[e.to] = v;
        V.eb(e.to);
      }
    }
    while (len(V)) {
      int v = V.back();
      V.pop_back();
      sz[v] += 1;
      if (p - sz[v] <= p / 2) return v;
      sz[par[v]] += sz[v];
    }
    return -1;
  }

  void build() {
    assert(G.is_prepared());
    assert(!G.is_directed());
    int N = G.N;

    vc<pair<int, int>> st = {{0, 0}};
    while (len(st)) {
      auto [lv, v] = st.back();
      st.pop_back();
      auto c = find(v);
      cdep[c] = lv;
      for (auto&& [frm, to, cost, id]: G[c]) {
        if (cdep[to] == -1) st.eb(lv + 1, to);
      }
    }
  }

  vc<vc<pair<int, E>>> collect(int root, E root_val) {
    /*
    root (v, path data v)  vector
     0 root root  i
    i 
    */
    vc<vc<pair<int, E>>> res = {{{root, root_val}}};
    for (auto&& e: G[root]) {
      int nxt = e.to;
      if (cdep[nxt] < cdep[root]) continue;
      vc<pair<int, E>> dat;
      int p = 0;
      dat.eb(nxt, f(root_val, e));
      par[nxt] = root;
      while (p < len(dat)) {
        auto [v, val] = dat[p++];
        for (auto&& e: G[v]) {
          if (e.to == par[v]) continue;
          if (cdep[e.to] < cdep[root]) continue;
          par[e.to] = v;
          dat.eb(e.to, f(val, e));
        }
      }
      res.eb(dat);
      res[0].insert(res[0].end(), all(dat));
    }
    return res;
  }
};
#line 3 "/home/maspy/compro/library/graph/hld.hpp"

template <typename Graph>
struct HLD {
  void doc() {
    print("HLO(N) ");
    print("LCA, LA  O(logN) ");
    print("");
    print(" DP");
    print("");
    print("dfs");
    print("edge idx -> in_tree ( tree ) ");
    print("LCA ");
  }

  Graph &G;
  int N;
  vector<int> LID, RID, head, V, parent, depth, root;
  vector<bool> in_tree;

  HLD & operator=(const HLD &) = default;

  HLD(Graph &G, int r = -1)
      : G(G),
        N(G.N),
        LID(G.N),
        RID(G.N),
        head(G.N, r),
        V(G.N),
        parent(G.N, -1),
        depth(G.N, -1),
        root(G.N, -1),
        in_tree(G.M, 0) {
    assert(G.is_prepared());
    int t1 = 0;
    if (r != -1) {
      dfs_sz(r, -1);
      dfs_hld(r, t1);
    } else {
      FOR(r, N) if (parent[r] == -1) {
        dfs_sz(r, -1);
        dfs_hld(r, t1);
      }
    }
    for (auto &&v: V) root[v] = (parent[v] == -1 ? v : root[parent[v]]);
  }

  void dfs_sz(int v, int p) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    // 
    FOR3_R(i, l, r - 1) {
      if (depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);
    }
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (depth[e.to] != -1) continue;
      in_tree[e.id] = 1;
      dfs_sz(e.to, v);
      sz[v] += sz[e.to];
      if (chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&e: G[v]) {
      if (!in_tree[e.id] || depth[e.to] <= depth[v]) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, times);
    }
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
  }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  /* k: 0-indexed */
  int LA(int v, int k) {
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  int subtree_size(int v) { return RID[v] - LID[v]; }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int move(int a, int b) {
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    // [, ] ""
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
  }

  void debug() {
    print("V", V);
    print("LID", LID);
    print("RID", RID);
    print("parent", parent);
    print("depth", depth);
    print("head", head);
    print("in_tree(edge)", in_tree);
    print("root", root);
  }
};
#line 2 "/home/maspy/compro/library/ds/unionfind.hpp"

struct UnionFind {
  int num;
  int comp;
  vc<int> size, par;
  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) {
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) { return find(x); }

  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) { return false; }
    comp--;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  vc<int> find_all() {
    vc<int> A(num);
    FOR(i, num) A[i] = find(i);
    return A;
  }
};
#line 6 "main.cpp"

void solve() {
  LL(N);
  Graph G(N);
  G.read_tree();
  auto C = find_centroids(G);
  int r1 = C[0];
  int r2 = (len(C) == 1 ? -1 : C[1]);

  HLD hld(G, r1);

  vc<set<ll>> nbd(N);
  for (auto&& e: G.edges) {
    nbd[e.frm].insert(e.to);
    nbd[e.to].insert(e.frm);
  }

  using T = tuple<ll, ll, ll>;
  vc<T> ANS;

  auto ADD = [&](ll a, ll b, ll c) -> void {
    assert(nbd[a].count(b));
    assert(!nbd[a].count(c));
    nbd[a].erase(b);
    nbd[b].erase(a);
    nbd[a].insert(c);
    nbd[c].insert(a);
    ANS.eb(a + 1, b + 1, c + 1);
  };

  auto solve_at = [&](ll x) -> void {
    ll r = hld.parent[x];
    if (len(nbd[x]) == 1) return;
    auto it = nbd[x].begin();
    if ((*it) == r) ++it;
    ll y = *it;
    // y 
    //  2 
    vc<pi> nbd2;
    for (auto&& a: nbd[y]) {
      for (auto&& b: nbd[a]) {
        if (b == r || b == y) continue;
        nbd2.eb(a, b);
      }
    }
    while (len(nbd2)) {
      auto [a, b] = nbd2.back();
      nbd2.pop_back();
      ADD(r, x, b);
      ADD(b, a, y);
      for (auto&& t: nbd[b]) {
        if (t == r || t == y) continue;
        nbd2.eb(b, t);
      }
      x = b;
    }
    ADD(r, x, y);
  };

  FOR(x, N) {
    if (x == r1 || x == r2) continue;
    if (hld.parent[x] == r1 || hld.parent[x] == r2) { solve_at(x); }
  }

  print(len(ANS));
  for (auto&& [a, b, c]: ANS) print(a, b, c);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}