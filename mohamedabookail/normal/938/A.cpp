/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
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
	char ar[] = {'a', 'e', 'i', 'o', 'u', 'y'};
	for (int i = 0; i < s.size() - 1; i++) {
		bool a = 0, b = 0;
		for (int j = 0; j < 6; j++) {
			if(s[i] == ar[j]) a = 1;
			if(s[i + 1] == ar[j]) b = 1;
		}
		if(a && b) {
			s.erase(s.begin() + i + 1, s.begin() + i + 2);
			i--;
		}
	}
	cout << s << line;
}