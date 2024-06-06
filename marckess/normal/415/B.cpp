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

#define find(v,x) (lower_bound(ALL(v), x) - v.begin() + 1);

ll n, a, b, x;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;

	while (n--) {
		cin >> x;
		ll y = x * a / b;
		cout << x - (y * b + a - 1) / a << " ";
	}
	cout << endl;

	return 0;
}