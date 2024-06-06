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

template<class T> ostream &operator<<(ostream& os, deque<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

template<class T> ostream &operator<<(ostream& os, set<T> V) {
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

const int MAX = 100010;
int n,p;
vector<PII> t;
set<int> czek;
deque<int> kol;
int res[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> p;
  t.resize(n);
  R(i,n){
    cin >> t[i].FI;
    t[i].SE = i;
  }
  sort(ALL(t));
  int time = 0;
  int j = 0;
  int toerase = -1;
  while(1){
    while(j < n && t[j].FI <= time){
      if(!czek.empty() && *czek.begin() > t[j].SE){
        kol.PB(t[j].SE);
      }
      czek.insert(t[j].SE);
      j++;
    }
    if(toerase != -1){
      czek.erase(toerase);
    }
    toerase = -1;
    if(kol.empty()){
      if(czek.empty()){
        if(j == n)break;
        time = t[j].FI;
      }else{
        kol.PB(*czek.begin());
      }
    }
    debug(time,kol,czek);
    if(!kol.empty()){
      time += p;
      res[kol[0]] = time;
      toerase = kol[0];
      kol.pop_front();
    }
  }
  R(i,n){
    cout << res[i] << " ";
  }
  cout << "\n";
}