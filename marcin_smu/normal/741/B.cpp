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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAX 1010
int n,m,w;
vector<int> d[MAX];
vector<PII> x;
bool vis[MAX];
int ww[MAX],b[MAX];
vector<int> dp;
void dfs(int a){
  if(vis[a])return;
  vis[a] = 1;
  x.PB({ww[a],b[a]});
  for(int ak:d[a])dfs(ak);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> w;
  R(i,n){
    cin >> ww[i];
  }
  R(i,n){
    cin >> b[i];
  }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dp.resize(w+1);
  R(i,n){
    if(!vis[i]){
      x.clear();
      dfs(i);
      vector<int> dp2 = dp;
      
      auto add = [&](int a,int b){
        R(i,w-a+1){
          maxi(dp[i+a], b + dp2[i]);
        }
      };
      
      int sumw = 0, sumb = 0;
      for(PII pom:x){
        add(pom.FI,pom.SE);
        sumw += pom.FI;
        sumb += pom.SE;
      }
      add(sumw,sumb);
    }
  }
  cout << dp[w] << "\n";
}