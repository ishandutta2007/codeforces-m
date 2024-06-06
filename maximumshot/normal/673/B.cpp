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
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	int l, r;

	l = 1;
	r = n;

	for(int x, y, i = 0;i < m;i++) {
		scanf("%d %d", &x, &y);
		if(x > y) swap(x, y);
		l = max(l, x);
		r = min(r, y);
	}

	printf("%d\n", max(0, r - l));

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}