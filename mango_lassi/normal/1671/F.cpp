#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

vector<vector<int>> opts = {{2, 1, 1, 1}, {3, 1, 2, 2}, {3, 2, 3, 1}, {4, 1, 3, 3}, {4, 1, 4, 1}, {4, 2, 3, 1}, {4, 2, 4, 4}, {4, 2, 5, 3}, {4, 3, 6, 1}, {5, 1, 4, 4}, {5, 1, 5, 2}, {5, 1, 6, 2}, {5, 2, 4, 4}, {5, 2, 5, 12}, {5, 2, 6, 12}, {5, 2, 7, 9}, {5, 2, 8, 3}, {5, 3, 5, 2}, {5, 3, 6, 4}, {5, 3, 7, 6}, {5, 3, 8, 6}, {5, 3, 9, 4}, {5, 4, 10, 1}, {6, 1, 5, 5}, {6, 1, 6, 3}, {6, 1, 7, 4}, {6, 1, 8, 3}, {6, 1, 9, 1}, {6, 2, 5, 10}, {6, 2, 6, 28}, {6, 2, 7, 35}, {6, 2, 8, 35}, {6, 2, 9, 30}, {6, 2, 10, 17}, {6, 2, 11, 8}, {6, 3, 5, 1}, {6, 3, 6, 13}, {6, 3, 7, 29}, {6, 3, 8, 41}, {6, 3, 9, 44}, {6, 3, 10, 45}, {6, 3, 11, 30}, {6, 4, 7, 1}, {6, 4, 8, 4}, {6, 4, 9, 7}, {6, 4, 10, 7}, {6, 4, 11, 11}, {7, 1, 6, 6}, {7, 1, 7, 4}, {7, 1, 8, 6}, {7, 1, 9, 6}, {7, 1, 10, 6}, {7, 1, 11, 2}, {7, 2, 6, 20}, {7, 2, 7, 55}, {7, 2, 8, 80}, {7, 2, 9, 95}, {7, 2, 10, 101}, {7, 2, 11, 94}, {7, 3, 6, 6}, {7, 3, 7, 50}, {7, 3, 8, 118}, {7, 3, 9, 186}, {7, 3, 10, 230}, {7, 3, 11, 260}, {7, 4, 7, 3}, {7, 4, 8, 18}, {7, 4, 9, 48}, {7, 4, 10, 85}, {7, 4, 11, 113}, {7, 5, 10, 2}, {7, 5, 11, 4}, {8, 1, 7, 7}, {8, 1, 8, 5}, {8, 1, 9, 8}, {8, 1, 10, 9}, {8, 1, 11, 11}, {8, 2, 7, 35}, {8, 2, 8, 96}, {8, 2, 9, 155}, {8, 2, 10, 207}, {8, 2, 11, 250}, {8, 3, 7, 21}, {8, 3, 8, 145}, {8, 3, 9, 358}, {8, 3, 10, 616}, {8, 3, 11, 859}, {8, 4, 7, 1}, {8, 4, 8, 26}, {8, 4, 9, 124}, {8, 4, 10, 313}, {8, 4, 11, 567}, {8, 5, 9, 3}, {8, 5, 10, 16}, {8, 5, 11, 53}, {9, 1, 8, 8}, {9, 1, 9, 6}, {9, 1, 10, 10}, {9, 1, 11, 12}, {9, 2, 8, 56}, {9, 2, 9, 154}, {9, 2, 10, 268}, {9, 2, 11, 389}, {9, 3, 8, 56}, {9, 3, 9, 350}, {9, 3, 10, 898}, {9, 3, 11, 1654}, {9, 4, 8, 8}, {9, 4, 9, 126}, {9, 4, 10, 552}, {9, 4, 11, 1404}, {9, 5, 9, 4}, {9, 5, 10, 48}, {9, 5, 11, 204}, {9, 6, 11, 1}, {10, 1, 9, 9}, {10, 1, 10, 7}, {10, 1, 11, 12}, {10, 2, 9, 84}, {10, 2, 10, 232}, {10, 2, 11, 427}, {10, 3, 9, 126}, {10, 3, 10, 742}, {10, 3, 11, 1967}, {10, 4, 9, 36}, {10, 4, 10, 448}, {10, 4, 11, 1887}, {10, 5, 9, 1}, {10, 5, 10, 43}, {10, 5, 11, 357}, {10, 6, 11, 6}, {11, 1, 10, 10}, {11, 1, 11, 8}, {11, 2, 10, 120}, {11, 2, 11, 333}, {11, 3, 10, 252}, {11, 3, 11, 1428}, {11, 4, 10, 120}, {11, 4, 11, 1302}, {11, 5, 10, 10}, {11, 5, 11, 252}, {11, 6, 11, 5}, {12, 1, 11, 11}, {12, 2, 11, 165}, {12, 3, 11, 462}, {12, 4, 11, 330}, {12, 5, 11, 55}, {12, 6, 11, 1} };

void mInc(ll& a, ll b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
ll mPow(ll a, ll b) {
	if (b & 1) return a * mPow(a, b - 1) % MOD;
	if (b == 0) return 1;
	return mPow(a*a % MOD, b / 2);
}

ll factDiv(ll a, ll b) {
	ll res = a;
	for (ll x = a - 1; x > b; --x) res = (res * x) % MOD;
	return res;
}

const int K = 11;
const int X = 11;
const int A = 2 * (K + 1);
ll modInv[K + 1];
ll fact[K + 1];
ll dp[A + 1][K + 1][X + 1][K + 1]; // How many ways to have total size A, count B, x local inversions and k inversions

void precalc(int i, int cur_siz, int cur_cou, int cur_x, int cur_k, ll mult) {
	if (i == opts.size()) return;
	
	int a = opts[i][0], b = opts[i][1], c = opts[i][2];
	if (cur_k + (a - 1) > K) return;
	ll opc = opts[i][3];

	ll nxt_mult = mult;
	for (int cou = 0;; ++cou) {
		int nxt_x = cur_x + b * cou;
		int nxt_k = cur_k + c * cou;
		if (nxt_x > X || nxt_k > K) break;

		int nxt_siz = cur_siz + a * cou;
		int nxt_cou = cur_cou + cou;

		precalc(i + 1, nxt_siz, nxt_cou, nxt_x, nxt_k, nxt_mult);
		if (cou > 0) mInc(dp[nxt_siz][nxt_cou][nxt_x][nxt_k], nxt_mult);
		nxt_mult = ((nxt_mult * opc) % MOD * modInv[cou + 1]) % MOD;
	}
}

void solve() {
	ll n;
	int k, x;
	cin >> n >> k >> x;

	ll res = 0;
	for (int a = 1; a <= min(n, (ll)2*k); ++a) {
		for (int b = 1; b <= min(k, a); ++b) {
			if (dp[a][b][x][k]) {
				ll mult = factDiv(n - a + b, n - a);
				ll add = mult * dp[a][b][x][k] % MOD;
				mInc(res, add);
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	fact[0] = 1;
	for (int k = 1; k <= K; ++k) {
		modInv[k] = mPow(k, MOD - 2);
		fact[k] = (fact[k-1] * k) % MOD;
	}
	precalc(0, 0, 0, 0, 0, 1);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}