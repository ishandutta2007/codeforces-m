#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, x, a, acu = -1;

	cin >> n >> x;
	while (n--) {
		cin >> a;
		acu += a + 1;
	}

	cout << (acu == x ? "YES" : "NO") << endl;

	return 0;
}