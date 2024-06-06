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

struct Sol{
  int n,q;
  string s,t;
  vector<int> l,r;
  vector<int> dp;
  
  bool run(){
    cin >> n >> q;
    cin >> s >> t;
    l.resize(q);
    r.resize(q);
    R(i,q){
      cin >> l[i] >> r[i];
      l[i]--;
    }
    int nn = 1;
    while(nn < n)nn *= 2;
    dp.resize(nn * 2);
    R(i,n){
      dp[i + nn] = t[i] == '1';
    }
    for(int i = nn-1; i; i--){
      dp[i] = dp[i * 2] + dp[i * 2 + 1];
    }
    for(int i = q - 1; i >= 0; i--){
      debug(dp);
      function<int(int,int,int)> sum = [&](int nr,int po,int ko) -> int{
//         debug(i,l[i],r[i],nr,po,ko);
        if(po >= r[i] || ko <= l[i])return 0;
        if(l[i] <= po && ko <= r[i]){
          return dp[nr];
        }
        if(dp[nr] == 0){
          dp[nr * 2] = 0;
          dp[nr * 2 + 1] = 0;
        }
        if(dp[nr] == ko - po){
          dp[nr * 2] = (ko - po) / 2;
          dp[nr * 2 + 1] = (ko - po) / 2;
        }
        return sum(nr * 2, po, (po + ko)/2) +
        sum(nr * 2 + 1, (po + ko)/2, ko);
      };
      int x = sum(1,0,nn);
      debug(i,x,l[i],r[i]);
      if(x * 2 == r[i] - l[i]){
        return 0;
      }
      int ile = 0;
      if(x * 2 < r[i] - l[i]){
        ile = 0;
      }else{
        ile = 1;
      }
      debug(ile);
      function<void(int,int,int)> ust = [&](int nr,int po,int ko){
        if(po >= r[i] || ko <= l[i])return;
        if(l[i] <= po && ko <= r[i]){
          dp[nr] = (ko - po) * ile;
          return;
        }
        if(dp[nr] == 0){
          dp[nr * 2] = 0;
          dp[nr * 2 + 1] = 0;
        }
        if(dp[nr] == ko - po){
          dp[nr * 2] = (ko - po) / 2;
          dp[nr * 2 + 1] = (ko - po) / 2;
        }
        ust(nr * 2, po, (po + ko)/2);
        ust(nr * 2 + 1, (po + ko)/2, ko);
        dp[nr] = dp[nr * 2] + dp[nr * 2 + 1];
      };
      ust(1,0,nn);
    }
    R(i,n){
      function<int(int,int,int)> sum = [&](int nr,int po,int ko) -> int{
        if(po >= i + 1 || ko <= i)return 0;
        if(i <= po && ko <= i + 1){
          return dp[nr];
        }
        if(dp[nr] == 0){
          dp[nr * 2] = 0;
          dp[nr * 2 + 1] = 0;
        }
        if(dp[nr] == ko - po){
          dp[nr * 2] = (ko - po) / 2;
          dp[nr * 2 + 1] = (ko - po) / 2;
        }
        return sum(nr * 2, po, (po + ko)/2) +
        sum(nr * 2 + 1, (po + ko)/2, ko);
      };
      if(sum(1,0,nn) != (s[i] == '1')){
        return 0;
      }
    }
    return 1;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    if(sol.run()){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
}