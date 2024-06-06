// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 3e5 + 5, M = 1 << 20;

int n, a[N], cnt[2][M];

LL ans;
 
int main() {
	read(n);
	int v = 0;
	cnt[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		v ^= a[i];
		ans += cnt[i & 1][v];
		cnt[i & 1][v]++;
	}
	print(ans);
	return 0;
}