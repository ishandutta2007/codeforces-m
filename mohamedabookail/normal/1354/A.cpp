/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
	int t; cin >> t;
	while(t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if(b >= a) cout << b << endl;
		else if(c <= d) cout << -1 << endl;
		else cout << b + ((a - b) + (c - d) - 1) / (c - d) * c << endl;
	}
}