#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

struct SSS{
  vector<vector<int>> d,drev; vector<int> ord,ss,cz,siz;
  int is,n;
  SSS(int _n) : n(_n) {
    d.resize(n); drev.resize(n);
    cz.resize(n); ss.resize(n, -1);
    siz.resize(n);
  }
  void add_edge(int a,int b){
    d[a].PB(b); drev[b].PB(a);
  }
  void dfs(int nr){
    if(cz[nr]) return;
    cz[nr] = 1;
    for(int ak:d[nr])
      dfs(ak);
    ord.PB(nr);
  }
  void dfs2(int nr,int s){
    if(ss[nr] != -1) return;
    ss[nr] = s;
    siz[s]++;
    for(int ak:drev[nr])
      dfs2(ak,s);
  }
  void licz(){
    R(i,n) dfs(i);
    is = 0;
    reverse(ALL(ord));
    for(int el:ord){
      if(ss[el] == -1){
        dfs2(el, is);
        is++;
      }
    }
  }
  vector<vector<int>> stworzgraf() {
    vector<vector<int>> res(is);
    R(i,n)for(int ak:d[i]){
      if(ss[i] != ss[ak])
        res[ss[i]].PB(ss[ak]);
    }
    for(auto &el:res){
      sort(ALL(el));
      el.resize(unique(ALL(el)) - el.begin());
    }
    return res;
  }
};

const int MAX = 101001;
int n,m,hh;
int u[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> hh;
  SSS sss(n);
  R(i,n){
    cin >> u[i];
  }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    R(_,2){
      if((u[a] + 1)%hh == u[b]){
        sss.add_edge(a,b);
      }
      swap(a,b);
    }
  }
  sss.licz();
  auto x = sss.stworzgraf();
  debug(x);
  int res = 1e9;
  int kt = 0;
  R(i,SZ(x)){
    if(SZ(x[i]) == 0){
      if(res > sss.siz[i]){
        res = sss.siz[i];
        kt = i;
      }
    }
  }
  cout << sss.siz[kt] << "\n";
  R(i,n){
    if(sss.ss[i] == kt){
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
}