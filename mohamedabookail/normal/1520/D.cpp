/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map < ll, ll > mp;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			mp[x - i - 1]++;
		}

		for(auto it : mp) {
			ans += it.second * (it.second - 1) / 2;
		}
		cout << ans << endl;
	}
}