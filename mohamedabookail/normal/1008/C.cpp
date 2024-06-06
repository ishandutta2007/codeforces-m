/**
 *    author:  Mohamed Abo_Okail
 *    created: O1/O4/2O2O
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
	int n; cin >> n;
	map < int, int > mp;
	set < int > st;
	int sm = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		st.insert(oo);
		mp[oo]++;
	}
	for(auto it : st) {
		sm += mp[it];
		mx = max(mx, mp[it]);
	}
	cout << sm - mx << o_o;
}