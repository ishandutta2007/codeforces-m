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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], ant;
ll res, acu;
map<ll, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	mp[0] = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		acu += a[i];

		if (mp.count(acu)) ant = max(ant, mp[acu] + 2);
		mp[acu] = i;
		res += i - ant + 1;
	}

	cout << res << endl;

	return 0;
}