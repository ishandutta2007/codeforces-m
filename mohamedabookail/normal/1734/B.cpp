/**
*    author:  Mohamed Abo Okail
*    created: 23/O9/2O22
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
		 int n;
		 cin >> n;
		 for (int i = 1; i <= n; i++) {
			 for (int j = 1; j <= i; j++) {
				 if(j == 1 || j == i) {
					cout << 1 << ' ';
				 }
				 else {
					cout << 0 << ' ';
				 }
			 }
			 cout << endl;
		 }
	}
}