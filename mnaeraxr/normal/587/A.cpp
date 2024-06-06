#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(2000000 + 1);
	int n; cin >> n;

	for (int i = 0; i < n; ++i){
		int val; cin >> val;
		v[val]++;
	}

	int ans = 0;
	for (int i = 0; i < (int)v.size(); ++i){
		v[i + 1] += v[i] / 2;
		if (v[i] & 1) ++ans;
	}

	cout << ans << endl;

	return 0;
}