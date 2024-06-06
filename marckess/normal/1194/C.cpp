#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
string s, t, p;
int cn[256];

void solve () {
	cin >> s >> t >> p;
	memset(cn, 0, sizeof(cn));

	for (char c : p) cn[c]++;

	for (int i = 0, j = 0; i < t.size(); i++, j++) {
		if (j < s.size() && t[i] == s[j]);
		else if (cn[t[i]]) s.insert(j, 1, t[i]), cn[t[i]]--;
		else {
			cout << "NO" << endl;
			return;
		}
	}
	if (s == t) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) {
		solve();
	}

	return 0;
}