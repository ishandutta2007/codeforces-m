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
#define MAXN 2000005

int n, q;
char s[MAXN];
int cnt[30][MAXN];

int main() {
	scanf("%d%d", &n, &q);
	scanf(" %s", s);
	REP (i, 0, n) {
		cnt[s[i] - 'a'][i]++;
		if (i > 0) {
			REP (j, 0, 30) {
				cnt[j][i] += cnt[j][i - 1];
			}
		}
	}
	REP (i, 0, q) {
		int l, r; scanf("%d%d", &l, &r);
		ll ans = 0;
		l--; r--;
		REP (j, 0, 30) {
			int len = cnt[j][r] - (l == 0 ? 0 : cnt[j][l - 1]);
			ans += (ll) len * (j + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}