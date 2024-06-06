#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

#include <time.h>

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

bool solve() {

	string a, b;

	cin >> a >> b;

	int p = (int)a.size() - 1;
	
	while(a[p] == 'z') {
		a[p] = 'a';
		p--;
	}

	a[p]++;

	if(a < b) cout << a << '\n';
	else cout << "No such string\n";

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}