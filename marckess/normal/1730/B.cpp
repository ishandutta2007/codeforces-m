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
int n, x[MX], t[MX];

ld isPos (ld m) {
	ld l = -1e18, r = 1e18;
	forn (i, n) {
		if (t[i] > m) return -1;
		l = max(l, x[i] - (m - t[i]));
		r = min(r, x[i] + (m - t[i]));
	}
	if (l <= r) return r;
	return -1;
}

void main_() {
	cin >> n;
	forn (i, n) cin >> x[i];
	forn (i, n) cin >> t[i];
	
	ld i = 0, j = 1e9, rep = 80;
	while (rep--) {
		ld m = (i + j) / 2;
		if (isPos(m) > 0) j = m;
		else i = m;
	}
	cout << fixed << setprecision(8) << isPos(j) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}