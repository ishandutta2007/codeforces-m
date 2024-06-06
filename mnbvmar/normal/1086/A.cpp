#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int xs[3], ys[3];
  for (int i = 0; i < 3; ++i)
    cin >> xs[i] >> ys[i];

  int x1 = -1, y1 = -1;
  const int M = 1024;
  int ans = 1e9;

  for (int x = 0; x <= M; ++x)
    for (int y = 0; y <= M; ++y) {
      int cand = 0;
      for (int i = 0; i < 3; ++i)
        cand += abs(xs[i] - x) + abs(ys[i] - y);
      if (ans > cand) {
        mini(ans, cand);
        x1 = x; y1 = y;
      }
    }

  set<PII> s;
  for (int i = 0; i < 3; ++i) {
    int x = x1, y = y1;
    s.emplace(x, y);
    while (x != xs[i]) {
      if (x > xs[i]) { --x; } else { ++x; }
      s.emplace(x, y);
    }
    while (y != ys[i]) {
      if (y > ys[i]) { --y; } else { ++y; }
      s.emplace(x, y);
    }
    debug(x, y, x1, y1);
  }

  cout << SZ(s) << "\n";
  for (auto [x, y] : s)
    cout << x << " " << y << "\n";
}