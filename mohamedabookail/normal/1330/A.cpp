/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O4/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n, x; cin >> n >> x;
		int ar[301] = {0}, ans = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			ar[oo] = 1;
		}
		for (int i = 2; i <= 300; i++) {
			ar[i] += ar[i - 1];
		}
		for (int i = 1; i <= 300; i++) {
			if(i - ar[i] <= x) {
				ans = i;
			}
		}
		cout << ans << o_o;
	}
}