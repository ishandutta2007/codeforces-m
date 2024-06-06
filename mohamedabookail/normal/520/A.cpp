/**
 *    author:  Mohamed Abo_Okail
 *    created: 15/O2/2O2O
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
	int n; string s; cin >> n >> s;
	set < char > st;
	for (auto ch : s) {
		st.insert(tolower(ch));
	}
	cout << (st.size() == 26 ? "YES" : "NO") << o_o;
}