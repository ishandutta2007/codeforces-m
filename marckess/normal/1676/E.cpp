// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 200005;
int n, q, a[MX];
vi v;

void main_() {
	cin >> n >> q;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	
	v.clear();
	forn (i, n) {
		int x = a[i];
		if (i)
			x += v.back();
		v.pb(x);
	}
	
	while (q--) {
		int x;
		cin >> x;
		
		int res = lower_bound(all(v), x) - v.begin();
		
		if (res == n) cout << -1 << endl;
		else cout << res + 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}