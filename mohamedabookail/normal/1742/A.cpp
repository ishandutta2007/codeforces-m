/**
*    author:  Mohamed Abo Okail
*    created: 13/1O/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		bool ok = 0;
		ok |= a == b + c;
		ok |= b == a + c;
		ok |= c == a + b;
		cout << (ok ? "YES" : "NO") << endl;
	}
}