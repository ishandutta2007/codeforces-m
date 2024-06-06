#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, p;

int f(int x) {
	return x / p;
}

int f(int l, int r) {
	return f(r) - f(l - 1);
}

int f(pii a) {
	return f(a.first, a.second);
}

bool solve() {

	scanf("%d %d", &n, &p);

	vec< pii > a(n);

	for(int i = 0;i < n;i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	ld ans = 0.0;

	for(int i = 0;i < n;i++) {
		ll good = 1ll * f(a[i]) * (a[(i + 1) % n].second - a[(i + 1) % n].first + 1) + 
			1ll * f(a[(i + 1) % n]) * (a[i].second - a[i].first + 1) - 
			1ll * f(a[i]) * f(a[(i + 1) % n]);
		ll all = 1ll * (a[i].second - a[i].first + 1) * (a[(i + 1) % n].second - a[(i + 1) % n].first + 1);
		ans += (ld)good / (ld)all;
	}

	cout.precision(10);
	cout << ans * 2000 << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}