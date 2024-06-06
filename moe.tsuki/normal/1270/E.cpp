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

const int maxn = 1234;
int n;
int x[maxn], y[maxn]; 

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> x[i] >> y[i];
}

void solve()
{
	while (true)
	{
		
		//F1 (i, n) cout << x[i] << ' ' << y[i] << '\n';
		//MEOW;
		int cnt = 0;
		F1 (i, n) if ((x[i] ^ y[i]) & 1) ++cnt;
		if (cnt && cnt < n)
		{
			cout << cnt << '\n';
			F1 (i, n) if ((x[i] ^ y[i]) & 1) cout << i << '\n';
			break;
		}
		if (cnt == n)
			F1 (i, n) ++y[i];
		F1 (i, n)
		{
			int a = x[i], b = y[i];
			x[i] = (a - b) / 2, y[i] = (a + b) / 2;
		}
	}
}

main()
{
	input();
	solve();
}