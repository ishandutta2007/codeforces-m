#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
int n, dp[MX];

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			dp[j]++;
	
	ll acu = 0;
	for (int i = 2; i <= n; i++) {
		(acu += dp[i - 1]) %= mod;
		(dp[i] += acu) %= mod;
	}
	
	cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}