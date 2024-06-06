#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, mod, a[MX], b[MX];
ll res = 1;
map<int, set<int>> mp;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) {
		cin >> a[i];
		mp[a[i]].insert(i);
	}
	
	forn (i, n) {
		cin >> b[i];
		mp[b[i]].insert(i);
	}

	cin >> mod;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		ll p = 1, tot = 0, dos = 0;

		for (int x : it->se) {
			tot++;

			if (a[x] == b[x]) {
				tot++;
				dos--;
			}
		}

		for (int i = 1; i <= tot; i++) {
			int x = i;
			while (x % 2 == 0) {
				x /= 2;
				dos++;
			}
			(p *= x) %= mod;
		}

		(p *= pot(2, dos)) %= mod;
		(res *= p) %= mod;
	}

	cout << res << endl;

	return 0;
}