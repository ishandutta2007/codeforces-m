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
#define MAXN 200005

int t;
ll n, pw[20];

int main() {
	scanf("%d", &t);
	pw[0] = 1;
	REP (i, 1, 16) {
		pw[i] = 10 * pw[i - 1];
	}
	while (t--) {
		scanf("%lld", &n);
		int ans = 0;
		RREP (i, 15, 0) {
			ll cur = pw[i] * 2050;
			while (n >= cur) {
				n -= cur;
				ans++;
			}
		}
		if (n != 0) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}