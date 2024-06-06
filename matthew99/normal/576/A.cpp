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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> ans;
	for (int i = 2; i <= n; ++i)
	{
		int x = i;
		for (int j = 2; j <= n; ++j)
		{
			bool flag = x % j == 0;
			while (!(x % j))
			{
				x /= j;
			}
			if (flag) break;
		}
		if (x == 1) ans.pb(i);
	}
	printf("%d\n", SZ(ans));
	for (auto it : ans) printf("%d ", it);
	return 0;
}