/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O4/2O2O
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
	int n, d; cin >> n >> d;
	vector < int > v(n);
	ll ans = 2;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		int f = (v[i] - v[i - 1]);
		if(f / d > 1) ans++;
		if(f / d > 1 && f % d || f / d > 2) ans++;
	}
	cout << ans << o_o;
}