
// Problem : A. Casimir's String Solitaire
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

string s;
int a, b, c;

void main_() {
	cin >> s;
	a = b = c = 0;
	
	for (char h : s) {
		if (h == 'A') a++;
		if (h == 'B') b++;
		if (h == 'C') c++;
	}
	
	if (a + c == b) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}