/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int main(){
	int n; cin >> n;
	int ret = 0;
	int maxi=0;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		ret = __gcd(ret, temp);
		maxi = max(maxi, temp);
	}
	cout << ((maxi / ret - n) % 2  ? "Alice" : "Bob") << endl;
	return 0;
}