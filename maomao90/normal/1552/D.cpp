#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 2000005
#define BUF 1000005

int t;
int n;
int a[MAXN];
bitset<MAXN> dp;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			a[i] = abs(a[i]);
		}
		bool ans = 0;
		dp = 0;
		dp[BUF] = 1;
		REP (i, 1, n + 1) {
			debug("%d: %d; %d: %d\n", a[i], (int) dp[BUF + a[i]], -a[i], (int) dp[BUF - a[i]]);
			if ((dp[BUF + a[i]]) || (dp[BUF - a[i]])) {
				ans = 1;
			}
			dp |= dp >> a[i];
			dp |= dp << a[i];
		}
		if (ans) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}