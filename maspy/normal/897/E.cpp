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
#line 1 "/home/maspy/compro/library/ds/intervals.hpp"
// https://codeforces.com/contest/1638/problem/E
template <typename T = ll, typename X = ll>
struct Intervals {
  static constexpr X INF = numeric_limits<X>::max();
  const T none_val;
  // none_val 
  int total_num;
  X total_len;
  map<X, T> dat;

  //  [l, r)  x in T 
  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0) {
    dat[-INF] = none_val;
    dat[INF] = none_val;
  }

  tuple<X, X, T> get(X x) {
    auto it = dat.upper_bound(x);
    X r = (*it).fi;
    auto [l, t] = *prev(it);
    return {l, r, t};
  }

  template <typename ADD, typename RM>
  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {
    if (L == R) return;
    assert(L < R);
    //  [l, r)  t 
    // 
    vc<tuple<X, X, T>> tmp;
    auto it = prev(dat.lower_bound(L));
    while (1) {
      auto [l, t] = *it;
      if (R < l) break;
      it = next(it);
      X r = (*it).fi;
      tmp.eb(l, r, t);
    }
    auto [lx, _, lt] = tmp[0];
    auto [__, rx, rt] = tmp.back();
    // 
    for (auto&& [l, r, t]: tmp) {
      dat.erase(l);
      if (t == none_val) continue;
      total_num--;
      total_len -= r - l;
      rm_f(l, r, t);
    }
    if (lt == t) chmin(L, lx);
    if (rt == t) chmax(R, rx);
    if (lx < L) {
      // [lx, L)
      dat[lx] = lt;
      if (lt != none_val) {
        total_num++;
        total_len += L - lx;
        add_f(lx, L, lt);
      }
    }
    if (R < rx) {
      // [R, rx)
      dat[R] = rt;
      if (rt != none_val) {
        total_num++;
        total_len += rx - R;
        add_f(R, rx, rt);
      }
    }
    // [L, R)
    dat[L] = t;
    if (t != none_val) {
      total_num++;
      total_len += R - L;
      add_f(L, R, t);
    }
  }

  void set(X L, X R, T t = 1) {
    auto f = [&](X L, X R, T t) -> void {};
    set(L, R, t, f, f);
  }

  void erase(X L, X R) {
    auto f = [&](X L, X R, T t) -> void {};
    set(L, R, none_val, f, f);
  }

  vc<tuple<X, X, T>> get(X L, X R) {
    vc<tuple<X, X, T>> res;
    auto it = prev(dat.lower_bound(L));
    while (1) {
      auto [l, t] = *it;
      if (R < l) break;
      it = next(it);
      X r = (*it).fi;
      X l0 = max(l, L);
      X r0 = min(r, R);
      if (l0 < r0) res.eb(l0, r0, t);
    }
    return res;
  }

  void debug() {
    auto it = dat.begin();
    print("Intervals");
    print("total_num", total_num);
    print("total_len", total_len);
    while (1) {
      auto [l, t] = *it;
      ++it;
      if (it == dat.end()) break;
      X r = (*it).fi;
      print("l, r, t", l, r, t);
    }
  }
};
#line 1 "/home/maspy/compro/library/mod/fast_div.hpp"
struct fast_div {
  // Min25 https://judge.yosupo.jp/submission/46090
  // 
  using i64 = long long;
  using u64 = unsigned long long;
  using u128 = __uint128_t;
  constexpr fast_div() : m(), s(), x() {}
  constexpr fast_div(int n)
      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}
  constexpr friend u64 operator/(u64 n, const fast_div& d) {
    return (u128(n) * d.x >> d.s) >> 64;
  }
  constexpr friend int operator%(u64 n, const fast_div& d) {
    return n - n / d * d.m;
  }
  constexpr std::pair<i64, int> divmod(u64 n) const {
    u64 q = n / *this;
    return {q, n - q * m};
  }

  int m;
  int s;
  u64 x;
};
#line 2 "/home/maspy/compro/library/mod/mod_pow.hpp"
ll mod_pow(ll a, ll n, int mod){
  fast_div fd(mod);
  a = a % fd;
  ll p = a;
  ll v = 1;
  while(n){
    if(n & 1) v = v * p % fd;
    p = p * p % fd;
    n >>= 1;
  }
  return v;
}
#line 5 "main.cpp"

void solve() {
  LL(N, Q, seed, vmax);
  auto rnd = [&]() -> ll {
    ll ret = seed;
    seed = (seed * 7 + 13) % (1000000007);
    return ret;
  };

  using QT = tuple<ll, ll, ll, ll, ll>;
  vi A(N);
  vc<QT> query(Q);

  FOR(i, N) { A[i] = (rnd() % vmax) + 1; }

  FOR(i, Q) {
    ll op = (rnd() % 4) + 1;
    ll l = (rnd() % N) + 1;
    ll r = (rnd() % N) + 1;
    if (l > r) swap(l, r);

    ll x = (op == 3 ? (rnd() % (r - l + 1)) + 1 : (rnd() % vmax) + 1);
    if (op <= 3) query[i] = {op, l, r, x, 0};
    elif (op == 4) {
      ll y = (rnd() % vmax) + 1;
      query[i] = {op, l, r, x, y};
    }
  }

  /*
  print(A);
  for (auto&& [op, l, r, x, y]: query) print(op, l, r, x, y);
  */

  Intervals<ll, int> I(0);
  FOR(i, N) I.set(i, i + 1, A[i]);

  for (auto&& [op, l, r, x, y]: query) {
    // I.debug();
    --l;
    if (op == 2) {
      I.set(l, r, x);
      continue;
    }
    auto get = I.get(l, r);
    if (op == 1) {
      for (auto&& [a, b, x0]: get) I.set(a, b, x0 + x);
    }
    vc<pi> dat;
    for (auto&& [a, b, x0]: get) dat.eb(x0, b - a);
    if (op == 3) {
      sort(all(dat));
      ll k = x;
      for (auto&& [val, cnt]: dat) {
        if (k <= cnt) {
          print(val);
          break;
        }
        k -= cnt;
      }
    }
    if (op == 4) {
      ll ANS = 0;
      for (auto&& [val, cnt]: dat) { ANS += mod_pow(val % y, x, y) * cnt % y; }
      print(ANS % y);
    }
  }
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