#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define VEC vector

template <typename T>
struct Matrix {
  ll H, W;
  vector<vector<T>> data;
  pi shape;
  Matrix(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)), shape({H,W}) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  vector<T>& operator[](ll i) { return data[i]; }
  bool operator==(Matrix<T>& other){
    if(H != other.H || W != other.W) return false;
    FOR(i, H) FOR(j, W){
      if(data[i][j] != other[i][j]) return false;
    }
    return true;
  }
  Matrix rot(){
    auto B = Matrix(W,H);
    FOR(i, W){
      FOR(j, H){
        B[i][j] = (*this)[j][W-1-i];
      }
    }
    return B;
  }
};


// [
ll in() {
  ll i;
  cin >> i;
  return i;
}

pi in2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
}

tuple<ll, ll, ll> in3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

tuple<ll, ll, ll, ll> in4() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  return {a, b, c, d};
}

tuple<ll, ll, ll, ll, ll> in5() {
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  return {a, b, c, d, e};
}

vi vin(int n) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
  }
  return A;
}

string sin() {
  string s;
  cin >> s;
  return s;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

Matrix<ll> matrixin(int H, int W){
  Matrix<ll> A(H, W);
  FOR(i, H){
    FOR(j, W){
      A[i][j] = in();
    }
  }
  return A;
}

Matrix<char> cmatrixin(int H, int W){
  Matrix<char> A(H, W);
  FOR(i, H){
    string S = sin();
    FOR(j, W){
      A[i][j] = S[j];
    }
  }
  return A;
}

// ]

// [
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}


void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

template <typename T>
string join(vector<T>& v){
  ostringstream os;
  for(auto&& x : v){
    os << x;
  }
  return os.str();
}

void YES() {print("YES");}
void NO() {print("NO");}
void Yes() {print("Yes");}
void No() {print("No");}
// ]

template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0LL);
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){return mp(A[i],i)<=mp(A[j],j);});
  return ids;
}

template <typename T>
int argmax(vector<T>& A){
  return max_element(all(A)) - A.begin();
}


template <typename T>
ostream& operator<<(ostream& os, Matrix<T>& A) {
  FOR(i, A.H){
    if(i) os << "\n";
    os << A[i];
  }
  return os;
}

template <class T, class U>
bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T& a, const U& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#line 3 "/home/maspy/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  int N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add_edge(int frm, int to, T cost = 1) {
    auto e = edge_t(frm, to, cost, M);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, M);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void print(bool detail=false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  vector<edge_t>& operator[](int v) { return G[v]; }
};
#line 4 "main.cpp"
void solve() {
  auto N = in();
  Graph<ll> G(N);
  FOR(_, N) {
    auto [a, b] = in2();
    G.add_edge(--a, --b);
  }
  vi deg(N);
  FORIN(e, G.edges) deg[e.frm]++, deg[e.to]++;
  queue<ll> que;
  FOR(v, N) {
    if (deg[v] == 1) que.push(v);
  }
  vi sz(N, 1);
  while (!que.empty()) {
    auto v = que.front();
    que.pop();
    FORIN(e, G[v]) {
      auto w = e.frm + e.to - v;
      if (deg[w] == 0) continue;
      deg[w] -= 1;
      sz[w] += sz[v];
      sz[v] = 0;
      if (deg[w] == 1) que.push(w);
    }
    deg[v] = 0;
  }
  ll ANS = N * (N - 1);
  FORIN(x, sz) { ANS -= x * (x - 1) / 2; }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto T = in();
  FOR(_, T) solve();

  // solve();

  return 0;
}