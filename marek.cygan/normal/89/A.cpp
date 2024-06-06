#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

const int N = 110000;
const int INF = 1001 * 1001 * 1001;
int t[N];

int main(){
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  if (n % 2 == 0){
    puts("0");
    return 0;
  }
  int rundy = INF;
  REP(i,n){
    int x;
    scanf("%d",&x);
    if (i % 2 == 0) rundy = min(rundy, x);
  }
  int minuta = m / (n/2+1);
  printf("%lld\n", min((LL)rundy, (LL)k * (LL)minuta));
  return 0;
}