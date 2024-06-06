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

const int maxn = 123456;
int t;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		F1 (i, n) cin >> a[i];
		bool ex = false;
		F1 (i, n) if (a[i] == k) ex = true;
		if (!ex)
		{
			cout << "No\n"; continue;
		}
		if (n == 1) 
		{
			cout << "Yes\n"; continue;
		}
		F1 (i, n) if (a[i] >= k) a[i] = 1; else a[i] = -1;
		F1 (i, n) a[i] += a[i - 1];
		int mn = maxn;
		bool ans = false;
		F1 (i, n) 
		{
			if (i > 1) mn = min(mn, a[i - 2]);
			if (a[i] > mn) 
			{
				cout << "Yes\n"; ans = true; break;
			}
		}
		if (!ans) cout << "No\n";
	}
}

main()
{
	input();
	solve();
}