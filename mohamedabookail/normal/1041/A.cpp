/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	int mx = -1, mn = 1e9 + 5;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	cout << mx - mn + 1 - n << endl;
}