#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll q;
ll n, m, k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;

	while (q--) {
		cin >> n >> m >> k;

		ll d = max(n, m);

		if (k < d) {
			cout << -1 << endl;
			continue;
		}

		k -= d;

		if ((n + m) % 2) {
			if (k % 2) k--;
			else d--;
		}
		if (k % 2) d--, k--;

		cout << d + k << endl;
	}

	return 0;
}