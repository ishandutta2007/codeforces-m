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

int n;

int sum, mx;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) 
	{
		int x; cin >> x; sum += x; mx = max(x, mx);
	}
}

void solve()
{
	cout << max(mx, (sum * 2 + n) / n);
}

main()
{
	input();
	solve();
}