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
#define pb emplace_back
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
#define MAXN 400005

int n;
int a[MAXN];
ii h[MAXN];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll ans = 0;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			ans += abs(a[i] - a[i - 1]);
		}
		ans += a[n];
		a[n + 1] = 0;
		REP (i, 1, n + 1) {
			h[i] = MP(a[i], i);
		}
		sort(h + 1, h + n + 1, greater<ii>());
		REP (_, 1, n + 1) {
			int i = h[_].SE;
			int x = a[i - 1], y = a[i], z = a[i + 1];
			if (y >= x && y >= z) {
				int ny = max(x, z);
				ans -= y - ny;
				y = ny;
			} else if (y <= x && y <= z) {
				continue;
				int ny = min(x, z);
				ans -= ny - y;
				y = ny;
			}
			a[i] = y;
		}
		printf("%lld\n", ans);
	}
	return 0;
}