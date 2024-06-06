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

ld S(ld l, int n) {
   ld alpha = 2 * pi / (ld)n;
   ld h = sqrt(l * l - l * l / (2.0 * (1 - cos(alpha))));
   ld s = (ld)n * (l * l / (2.0 * (1 - cos(alpha)))) * sin(alpha) / 2;
   return s * h / 3.0;
}

bool solve() {
	
	ld l1, l2, l3;
	
	cin >> l1 >> l2 >> l3;
	
	cout.precision(20);
	cout << fixed;
	
	cout << S(l1, 3) + S(l2, 4) + S(l3, 5) << '\n';
	
 	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}