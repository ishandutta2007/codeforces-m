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

  int n;
  cin >> n;

  VI data(n);
  for (int &x : data) { cin >> x; --x; }

  VI where_is(n);
  for (int i = 0; i < n; ++i) { where_is[data[i]] = i; }

  vector<PII> ans;

  auto MakeSwap = [&](int a, int b) {
    assert(abs(a - b) >= n / 2);
    swap(data[a], data[b]);
    swap(where_is[data[a]], where_is[data[b]]);
    ans.emplace_back(a, b);
#ifdef LOCAL
    debug(a, b, data);
#endif
  };

  auto Fix = [&](int idx) {
    if (data[idx] == idx) { return; }
    int loc = where_is[idx];
    if (loc < n / 2) {
      MakeSwap(loc, n - 1); loc = n - 1;
    } else {
      MakeSwap(loc, 0); loc = 0;
    }

    if ((loc < n / 2) == (idx < n / 2)) {
      MakeSwap(loc, n - 1 - loc); loc = n - 1 - loc;
    }

    MakeSwap(loc, idx);

  };

  for (int i = 1; i < n - 1; ++i) {
    Fix(i);
  }

  if (data[0] != 0) {
    MakeSwap(0, n - 1);
  }
  assert(is_sorted(ALL(data)));

  cout << SZ(ans) << "\n";
  for (auto [a,b] : ans) { cout << a+1 << " " << b+1 << "\n" ;}
}