#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 2345678;
int n;
int dp[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

void solve()
{
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 2; i <= 20; ++i)
	{
		int cur = -1;
		for (int j = i; j >= 0; j -= 2)
			cur += 1 << j;
		dp[cur] = dp[cur + 1] = 1;
	}
	cout << dp[n] << '\n';
	//F1 (i, 100) {dbgg(i); dbg(dp[i]);} 
}

main()
{
	input();
	solve();
}