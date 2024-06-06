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

const int MX = 105;
int n, k, a[MX];

void main_() {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	ll res = 0;
	forn (i, n - 2 * k)
		res += a[i];
		
	map<int, int> mp;
	int mx = 0;
	for (int i = n - 2 * k; i < n; i++)
		mx = max(mx, ++mp[a[i]]);
	
	cout << res + max(0, mx - k) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}