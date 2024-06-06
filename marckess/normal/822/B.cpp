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

int n, m, mx = 1e9;
vi res;
string a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> a >> b;

	for (int i = 0; i + n <= m; i++) {
		int acu = 0;
		vi p;
		for (int j = 0; j < n; j++)
			if (a[j] != b[i+j]) {
				acu++;
				p.push_back(j+1);
			}
		
		if (acu < mx) {
			mx = acu;
			res = p;
		}
	}

	cout << mx << endl;
	for (int x : res) cout << x << " ";
	cout << endl;

	return 0;
}