#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int a = 0, b = 0, x, n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	forn(i,3) {
		cin >> x;
		a += x;
	}
	forn(i,3) {
		cin >> x;
		b += x;
	}
	cin >> n;

	if ((a+4)/5 + (b+9)/10 <= n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}