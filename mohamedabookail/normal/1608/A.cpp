/**
*    author:  Mohamed Abo Okail
*    created: 11/12/2O21
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
		int n; cin >> n;
		for (int i = 2; i <= n + 1; i++) {
			cout << i << ' ';
		}
		cout << endl;
	}
}