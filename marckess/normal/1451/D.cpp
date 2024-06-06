#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll d, k;

ll sq (ll n) {
	return n * n;
}

ll m_sqrt (ll n) {
	ll x = sqrt(n), res;
	for (ll i = x - 3; i <= x + 3; i++)
		if (i * i <= n)
			res = i;
	return res;
}

void solve () {
	cin >> d >> k;
	ll mx = 0;
	for (ll p = 0; p * k <= d; p++) {
		ll q = m_sqrt(sq(d) - sq(p * k)) / k;
		mx = max(mx, p + q);
	}
	if (mx % 2 == 0) cout << "Utkarsh" << endl;
	else cout << "Ashish" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}