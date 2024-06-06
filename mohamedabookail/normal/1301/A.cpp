/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		string a, b, c; cin >> a >> b >> c;
		bool bol = 1;
		for (int i = 0; i < a.size(); i++) {
			if(a[i] != c[i] && b[i] != c[i]) bol = 0; 
		}
		cout << (bol ? "YES" : "NO") << o_o;
	}
}