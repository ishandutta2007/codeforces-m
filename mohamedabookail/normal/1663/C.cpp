/**
*    author:  Mohamed Abo Okail
*    created: O1/O4/2O22
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

	int n;
	cin >> n;
	ll sum = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
	}
	cout << sum << endl;
}