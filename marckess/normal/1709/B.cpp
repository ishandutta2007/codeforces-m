#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 100005;
int n, q, a[MX];
ll izq[MX], der[MX];

void main_() {
	cin >> n >> q;
	forr (i, 1, n)
		cin >> a[i];
	
	forr (i, 1, n) {
		der[i] = max(0, a[i] - a[i + 1]);
		der[i] += der[i - 1];
	}
	
	for (int i = n; i >= 1; i--) {
		izq[i] = max(0, a[i] - a[i - 1]);
		izq[i] += izq[i + 1];
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		if (l < r) cout << der[r - 1] - der[l - 1] << endl;
		else cout << izq[r + 1] - izq[l + 1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}