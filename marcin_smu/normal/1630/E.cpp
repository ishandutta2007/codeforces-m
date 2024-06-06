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

const int P = 998244353;

int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}

int mul(int a,int b){
  return a * b % P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
const int MAX = 1e6 + 10;
int sil[MAX];
int odw[MAX];
struct Sol{
  vector<int> ile;
  int res = 0;
  int liczba = 0;
  int n;
  vector<int> war;
  void licz(int dziel,int kr){
    debug("licz",dziel,kr);
    int pom = sil[n / dziel];
    R(i,SZ(war)){
      pom = mul(pom, odw[war[i] / dziel]);
    }
    
    debug(pom);
    add(liczba, mul(kr,pom));
    
    int wyn = 0;
    int mn = pot(mul(n / dziel, n / dziel - 1), P-2);
    R(i,SZ(war))if(war[i] >= 2){
      add(wyn, mul(mul(mn,pom), mul(war[i] / dziel, war[i] / dziel - 1)));
    }
    debug(wyn);
    add(res, mul(kr,mul(wyn, n)));
    debug(pom, res);
  }
  void run(){
    cin >> n;
    ile.resize(n);
    R(i,n){
      int pom;
      cin >> pom;
      pom--;
      ile[pom]++;
    }
    R(i,n)if(ile[i] != 0){
      war.PB(ile[i]);
    }
    if(SZ(war) == 1){
      cout << "1\n";
      return;
    }
    debug(war);
    int cd = 0;
    for(int el:war){
      cd = __gcd(cd, el);
    }
    debug("------------", cd);
    vector<int> kr(n + 1);
    for(int i = 1; i <= n; i++){
      kr[__gcd(i,n)]++;
    }
    for(int i = 1; i <= n; i++){
      if(cd % i == 0){
        licz(i, kr[n / i]);
      }
    }
    debug(res, liczba);
//     assert(res % n == 0);
//     assert(liczba % n == 0);
    cout << (n - mul(res, pot(liczba, P - 2)) + P) % P<< "\n";
  }
};


int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  sil[0] = 1;
  R(i,MAX-1){
    sil[i + 1] = mul(sil[i], i + 1);
  }
  R(i,MAX){
    odw[i] = pot(sil[i], P-2);
  }
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}