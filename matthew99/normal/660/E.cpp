#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 1000100;

int fac[maxn + 5], ifac[maxn + 5], inv[maxn + 5];

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	REP(i, 1, maxn + 1) inv[i] = (LL)ifac[i] * fac[i - 1] % Mod;
}

int n, m;

int pw[maxn + 5], w[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%d", &n, &m);
	int tmp = (LL)(m - 1) * fpm(m, Mod - 2, Mod) % Mod;
	pw[0] = fpm(m, n, Mod);
	REP(i, 0, n) pw[i + 1] = (LL)pw[i] * tmp % Mod;
	REP(i, 0, n) w[i] = (LL)ifac[i] * pw[i] % Mod;
	int ret = pw[0];
	REP(i, 0, n)	
	{
		int foo = (LL)fac[n] * ifac[n - i - 1] % Mod * inv[i + 1] % Mod;
		foo = (LL)foo * w[i] % Mod;
		(ret += foo) %= Mod;
	}
	printf("%d\n", ret);
	return 0;
}