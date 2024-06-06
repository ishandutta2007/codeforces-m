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

int n,m,r,c,x,y;
const int inf = 1e12;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> r >> c >> x >> y;
  r--;c--;
  vector<string> z(n);
  R(i,n){
    cin >> z[i];
  }
  vector<vector<int>> odl(n,vector<int>(m,inf));
  set<pair<int,PII>> secik;
  auto add = [&](int i,int j,int od){
    if(i < 0 || i >= n || j < 0 || j >= m || z[i][j] == '*')return;
    if(odl[i][j] > od){
      debug(i,j,od);
      odl[i][j] = od;
      secik.insert({od,{i,j}});
    }
  };
  add(r,c,0);
  while(SZ(secik)){
    auto xx = secik.begin();
    int i = xx->SE.FI;
    int j = xx->SE.SE;
    int od = xx->FI;
    secik.erase(xx);
    if(od != odl[i][j])continue;
    for(int d:{-1,1}){
      add(i + d, j, od);
      add(i, j + d, od +1);
    }
  }
  int res = 0;
  R(i,n)R(j,m){
    int yy = (odl[i][j] - c + j) / 2;
    int xx = (odl[i][j] + c - j) / 2;
    debug(i,j,odl[i][j],xx,yy);
    if(xx <= x && yy <= y){
      res++;
    }
  }
  cout << res << "\n";
}