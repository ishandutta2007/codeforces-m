#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 200100;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int n;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	if (n == 1)
	{
		printf("%d\n", a[0]);
		return 0;
	}
	if (n & 1)
	{
		static int nxt[maxn + 5];
		REP(i, 0, n - 1)
		{
			if (i & 1) nxt[i] = (a[i] - a[i + 1]) % Mod;
			else nxt[i] = (a[i] + a[i + 1]) % Mod;
		}
		memcpy(a, nxt, sizeof a);
		--n;
	}
	prepare();
	int ans = 0;
	REP(i, 0, n)
	{
		int tmp = (LL)fac[(n >> 1) - 1] * ifac[i >> 1] % Mod * ifac[(n >> 1) - (i >> 1) - 1] % Mod;
		if ((i & 1) && (((n >> 1) - 1) & 1)) tmp = -tmp;
		(ans += (LL)tmp * a[i] % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}