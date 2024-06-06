
// Problem : B. Divan and a New Project
// Contest : Codeforces - Codeforces Round #757 (Div. 2)
// URL : https://codeforces.com/contest/1614/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void main_() {
	int n;
	vii a;
	
	cin >> n;
	forn (i, n) {
		int x;
		cin >> x;
		a.pb({x, i + 1});
	}
	
	sort(all(a), greater<ii>());
	
	vi res(n + 1);
	int f = 1;
	ll s = 0;
	forn (i, n) {
		res[a[i].se] = f * (i / 2 + 1), f *= -1;
		s += 2ll * a[i].fi * abs(res[a[i].se]);
	}
	
	cout << s << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}