#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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


vector<int> res0;
vector<int> res1;
void licz(int bit,vector<int> t){
  if(bit == -1 || SZ(t) <= 1)return;
  vector<int> a,b;
  R(i,SZ(t)){
    if((t[i] >> bit) & 1){
      a.PB(t[i]);
      res1[bit] += SZ(b);
    }else{
      b.PB(t[i]);
      res0[bit] += SZ(a);
    }
  }
  licz(bit-1, a);
  licz(bit-1, b);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<int> t(n);
  R(i,n)cin >> t[i];
  res0.resize(30);
  res1.resize(30);
  licz(29, t);
  int res = 0;
  int x = 0;
  debug(res0,res1);
  R(i,30){
    if(res0[i] <= res1[i]){
      res += res0[i];
    }else{
      res += res1[i];
      x += 1 << i;
    }
  }
  cout << res << " " << x << "\n";
}