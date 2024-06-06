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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 510;

int pw[maxn + 5];

int n;
int cnt[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw[0] = 1;
	REP(i, 0, maxn) pw[i + 1] = (pw[i] << 1) % Mod;
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		if (~x) ++cnt[--x];
	}

	int ans = (pw[n - 1] + n - 1) % Mod;
	REP(i, 0, n) (ans -= pw[cnt[i]]) %= Mod;
	(ans += Mod) %= Mod;

	printf("%d\n", ans);
	return 0;
}