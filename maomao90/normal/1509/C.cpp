#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 2005

int n;
int s[MAXN];
ll dp[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &s[i]);
	}
	sort(s, s + n);
	REP (i, 0, n) {
		REP (j, 0, n) {
			dp[i][j] = LINF;
		}
	}
	REP (i, 0, n) {
		dp[i][i] = 0;
		RREP (j, i - 1, 0) {
			mnto(dp[i][j], dp[i - 1][j] + s[i] - s[j]);
			mnto(dp[i][j], dp[i][j + 1] + s[i] - s[j]);
		}
	}
	printf("%lld\n", dp[n - 1][0]);
	return 0;
}