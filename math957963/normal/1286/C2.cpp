#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200010


int main() {
	int a[100][30];
	int b[100][30];
	int e[100][30];
	int d[110];
	f(i, 100) {
		f(j, 30) {
			a[i][j] = 0;
			b[i][j] = 0;
          e[i][j]=0;
		}
	}
	char c[N];
	f(i, N)c[i] = 0;
	int n, k, nn;
	int x, y, z, yy, zz;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	if (n <=3) {
		f(i, n) {
			printf("? %d %d\n", i + 1, i + 1);
			fflush(stdout);
			scanf("%s", c);
			d[i] = c[0];
			c[0] = 0;
		}
		printf("! ");
		f(i,n)printf("%c", d[i]);
		printf("\n");
		fflush(stdout);
		return 0;
	}
	nn = n;
	n = (2 * n) / 3;
	printf("? 1 %d\n", n);
	fflush(stdout);
	k = n * (n + 1);
	k = k / 2;
	y = (n + 1) / 2;
	f(i, k) {
		scanf("%s", c);
		x = strlen(c);
		if (x <= y) {
			f(j, x)a[x][(c[j] - 'a')]++;
		}
		f(i, x + 1)c[i] = 0;
	}
	for (int i = y - 2; i >= 0; i--) {
		f(j, 30)a[i + 2][j] -= a[i + 1][j];
	}
	f(i, y - 1) {
		f(j, 30)a[i + 1][j] -= a[i + 2][j];
	}
	printf("? 1 %d\n", n - 1);
	fflush(stdout);
	k = n * (n - 1);
	k = k / 2;
	y = n / 2;
	f(i, k) {
		scanf("%s", c);
		x = strlen(c);
		if (x <= y) {
			f(j, x)b[x][(c[j] - 'a')]++;
		}
		f(i, x + 1)c[i] = 0;
	}
	for (int i = y - 2; i >= 0; i--) {
		f(j, 30)b[i + 2][j] -= b[i + 1][j];
	}
	f(i, y - 1) {
		f(j, 30)b[i + 1][j] -= b[i + 2][j];
	}
	if (n % 2 == 0) {
		y = n / 2;
		while (y >= 1) {
			z = y - 1;
			zz = n - y;
			f(j, 30)if (b[y][j] > 0)d[z] = j;
			a[y][d[z]]--;
			f(j, 30)if (a[y][j] > 0)d[zz] = j;
			y--;
			b[y][d[zz]]--;
		}
	}
	else {
		y = (n + 1) / 2;
		zz = y - 1;
		f(j, 30)if (a[y][j] > 0)d[zz] = j;
		y--;
		b[y][d[zz]]--;
		while (y >= 1) {
			z = y - 1;
			zz = n - y;
			f(j, 30)if (b[y][j] > 0)d[z] = j;
			a[y][d[z]]--;
			f(j, 30)if (a[y][j] > 0)d[zz] = j;
			y--;
			b[y][d[zz]]--;
		}
	}

	printf("? %d %d\n",(2*n)+2-nn, nn);
	fflush(stdout);
	k = (2 * nn) - (2 * n) - 1;
  	y = (k+1) / 2;
	k = k * (k + 1);
	k = k / 2;

	f(i, k) {
		scanf("%s", c);
		x = strlen(c);
		if (x <= y) {
			f(j, x)e[x][(c[j] - 'a')]++;
		}
		f(i, x + 1)c[i] = 0;
	}
	for (int i = y - 2; i >= 0; i--) {
		f(j, 30)e[i + 2][j] -= e[i + 1][j];
	}
	f(i, y - 1) {
		f(j, 30)e[i + 1][j] -= e[i + 2][j];
	}
	f(j, 30)if (e[y][j] > 0)d[n] = j;
	for (int i = n + 1; i < nn; i++) {
		e[y - (i - n)][d[n - (i - n)]]--;
		f(j, 30)if (e[y - (i - n)][j] > 0)d[i] = j;
	}




	printf("! ");
	f(i, nn)printf("%c", 'a' + d[i]);
	printf("\n");
	fflush(stdout);


	return 0;
}