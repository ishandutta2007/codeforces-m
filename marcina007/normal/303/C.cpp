#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

int n,k,a[MAXN],last[MAXN],cnt[MAXN],bad[MAXN][7],wyb[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> k;
    REP(i,n) cin >> a[i];
	//sol
    REP(i,n) {
        REP(j,i) {
            int q = abs(a[i] - a[j]);
            if(cnt[q] <= 5 && last[q] != i) {
                bad[q][cnt[q]++] = i;
                last[q] = i;
            }
        }
    }
    FOR(m,1,MAXN-1) {
        int act = 0;
        for(int i=m; i<MAXN; i+=m) {
            if(act > k) break;
            REP(j,cnt[i])
                if(wyb[bad[i][j]] != m)
                    wyb[bad[i][j]] = m, act++;
        }
        if(act <= k){cout << m << endl; return 0;}
    }
	//out
	return 0;
}