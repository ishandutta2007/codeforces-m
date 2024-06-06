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

const int maxn = 500;

int n;
int a[maxn + 5];
int dp[maxn + 5][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n + 1) dp[i][i] = 0;
	REP(l, 1, n + 1)
		REP(i, 0, n - l + 1)
		{
			int j = i + l;
			dp[i][j] = oo;
			if (a[i] == a[j - 1]) dp[i][j] = dp[i + 1][j - 1];
			REP(k, i, j - 1)
				if (a[i] == a[k]) chkmin(dp[i][j], dp[i + 1][k] + dp[k + 1][j] + 1);
		}
	printf("%d\n", dp[0][n] + 1);
	return 0;
}