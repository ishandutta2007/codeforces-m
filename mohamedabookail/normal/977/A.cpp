/**
*    author:  Mohamed Abo Okail
*    created: O1/11/2O21
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
	
	ll n, k; cin >> n >> k;
	while(k--) {
		if(n % 10) n--;
		else n /= 10;
	}
	cout << n << endl;
}