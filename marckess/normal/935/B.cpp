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

void main_() {
	string s;
	cin >>  s>> s;
	int res = 0;
	int x = 0, y = 0, f = -1;
	for (char c : s) {
		if (c == 'U') x++;
		else y++;
		if (x != y) {
			if (x > y) {
				if (f == 0)
					res++;
				f = 1;
			} else {
				if (f == 1)
					res++;
				f = 0;
			}
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}